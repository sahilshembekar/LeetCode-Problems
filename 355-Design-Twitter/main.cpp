//Without pass by refrence / pointers

class Twitter {
public:
    class Tweet {
        public:
        int tid; //tweet id
        int createdAt; //time at which it was created
        
        public:
        Tweet(int tweetId, int time) { //constructor
            this->tid = tweetId;
            this->createdAt = time;
        }
    };
    //Structure of the comp operator
    //overloading for comparison
    struct comp{
      bool operator() (Tweet &t1, Tweet &t2){
          return t1.createdAt > t2.createdAt;
      } 
    };
    
    
        unordered_map<int, unordered_set<int>> followed; //only unique users are followed hence set
        unordered_map<int, vector<Tweet>> tweets; // tweets will be default unique hence vector also they will be of type Tweet
        int time = 0; //initilize the start time here //used for time in tweets
    Twitter() {
        
    }
    
    
    //Creating a new tweet
    void postTweet(int userId, int tweetId) {
        follow(userId,userId); //make the user follow themselves
        
        if(tweets.find(userId) == tweets.end()) {
            //if there is no list of tweets for this user then we make a new list/vector
            tweets.insert({userId,vector<Tweet>()});
        }
        time++; //starts the time at 1 then add 1 every time before a new tweet
        
        Tweet newTweet(tweetId,time); //make a new tweet // problem does not have text constraint //only userId needed and time is needed for ordering 
    
        tweets[userId].push_back(newTweet); //tweet added for the corresponding user
    }
    
    
    // Retrieve the 10 most recent tweet ids in the user's news feed 
    //Each item in the news feed must be posted by users who the user followed or by the user themself 
    //Tweets must be ordered from most recent to least recent
    //TC = O(nk) where n is the total number of people the user follow and k is the total number of tweets tweeted by these n number of people
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> setCopy = followed[userId]; //make a copy of the set 
        priority_queue<Tweet, vector<Tweet>, comp> pq;
        if(!setCopy.empty()) {//if the set is not empty
            for (auto user : setCopy) {
                //go over each user in the set // basically each person that we follow includes ourselves
                vector<Tweet> ftweets = tweets[user]; // Copy the tweets belonging to each person into new vector
                if(!ftweets.empty()) {
                    //if the user has actually tweeted anything the go inside
                    for (auto tw : ftweets) {
                        // go over each tweet in the list/vector of tweets
                        pq.push(tw); //push it inside our priority queue
                        if(pq.size() > 10) {
                            pq.pop(); //we need only 10 recent tweets //so when >10, pop
                        }
                    }
                }
            }
        }
        vector <int> result; //to return the output in desired form // i.e. only the TweetId
        while(!pq.empty()) {
            // do till our priority queue is not empty
            result.insert(result.begin(),pq.top().tid); // (position, and tweetId from the top of the priority queue and downwards)
            pq.pop(); //pop after every recent tweet is inserted
        }
        return result;
        
    }
    
    
    //Follower follows a followee 
    // Time = O(1)
    void follow(int followerId, int followeeId) {
        //we are the followers // we are the key in the followed table 
        // we follow (followerID) a set of people (followeeID)
        if (followed.find(followerId) == followed.end()) {
            // basically if we traverse the map and are unable to find this users set of followers 
            //This user does not follow anyone as of now
            followed.insert({followerId,unordered_set<int>()}); //Just initilize the map at this location
        }
        followed[followerId].insert(followeeId); //Add the followee at the followerId key
    }
    
    
    
    //Follower unfollows a followee 
    // Time = O(1)
    void unfollow(int followerId, int followeeId) {
        if (followed.find(followeeId) != followed.end()) {
            //basically if we find the correcposning set for the key 
            if (followed[followerId].find(followeeId) != followed[followerId].end() && followerId != followeeId) {
                // basically if find the user that we want to unfollow
                // Also, we should not unfollow ourselves hence the other check
                followed[followerId].erase(followeeId);  //unfollow
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

//With pass by reference /pointers

class Twitter {
public:
    class Tweet {
        public:
        int tid; //tweet id
        int createdAt; //time at which it was created
        
        public:
        Tweet(int tweetId, int time) { //constructor
            this->tid = tweetId;
            this->createdAt = time;
        }
    };
    //Structure of the comp operator
    //overloading for comparison
    struct comp{
      bool operator() (Tweet &t1, Tweet &t2){
          return t1.createdAt > t2.createdAt;
      } 
    };
    
    
        unordered_map<int, unordered_set<int>> followed; //only unique users are followed hence set
        unordered_map<int, vector<Tweet*>> tweets; // tweets will be default unique hence vector also they will be of type Tweet
        int time = 0; //initilize the start time here //used for time in tweets
    Twitter() {
        
    }
    
    
    //Creating a new tweet
    void postTweet(int userId, int tweetId) {
        follow(userId,userId); //make the user follow themselves
        
        if(tweets.find(userId) == tweets.end()) {
            //if there is no list of tweets for this user then we make a new list/vector
            tweets.insert({userId,vector<Tweet*>()});
        }
        time++; //starts the time at 1 then add 1 every time before a new tweet
        
        Tweet *t = new Tweet(tweetId,time); //make a new tweet // problem does not have text constraint //only userId needed and time is needed for ordering 
        //via pointer
        tweets[userId].push_back(t); //tweet added for the corresponding user
    }
    
    
    // Retrieve the 10 most recent tweet ids in the user's news feed 
    //Each item in the news feed must be posted by users who the user followed or by the user themself 
    //Tweets must be ordered from most recent to least recent
    //TC = O(nk) where n is the total number of people the user follow and k is the total number of tweets tweeted by these n number of people
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> setCopy = followed[userId]; //make a copy of the set 
        priority_queue<Tweet, vector<Tweet>, comp> pq;
        if(!setCopy.empty()) {//if the set is not empty
            for (auto user : setCopy) {
                //go over each user in the set // basically each person that we follow includes ourselves
                vector<Tweet*> ftweets = tweets[user]; // Copy the tweets belonging to each person into new vector
                if(!ftweets.empty()) {
                    //if the user has actually tweeted anything the go inside
                    for (auto *tw : ftweets) {
                        // go over each tweet in the list/vector of tweets
                        pq.push(*tw); //push it inside our priority queue
                        if(pq.size() > 10) {
                            pq.pop(); //we need only 10 recent tweets //so when >10, pop
                        }
                    }
                }
            }
        }
        vector <int> result; //to return the output in desired form // i.e. only the TweetId
        while(!pq.empty()) {
            // do till our priority queue is not empty
            result.insert(result.begin(),pq.top().tid); // (position, and tweetId from the top of the priority queue and downwards)
            pq.pop(); //pop after every recent tweet is inserted
        }
        return result;
        
    }
    
    
    //Follower follows a followee 
    // Time = O(1)
    void follow(int followerId, int followeeId) {
        //we are the followers // we are the key in the followed table 
        // we follow (followerID) a set of people (followeeID)
        if (followed.find(followerId) == followed.end()) {
            // basically if we traverse the map and are unable to find this users set of followers 
            //This user does not follow anyone as of now
            followed.insert({followerId,unordered_set<int>()}); //Just initilize the map at this location
        }
        followed[followerId].insert(followeeId); //Add the followee at the followerId key
    }
    
    
    
    //Follower unfollows a followee 
    // Time = O(1)
    void unfollow(int followerId, int followeeId) {
        if (followed.find(followeeId) != followed.end()) {
            //basically if we find the correcposning set for the key 
            if (followed[followerId].find(followeeId) != followed[followerId].end() && followerId != followeeId) {
                // basically if find the user that we want to unfollow
                // Also, we should not unfollow ourselves hence the other check
                followed[followerId].erase(followeeId);  //unfollow
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */