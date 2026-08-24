class Twitter {
public:

    int time = 0;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // user -> people they follow
    unordered_map<int, unordered_set<int>> following;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> ans;

        // max heap: {time, tweetId}
        priority_queue<pair<int, int>> pq;

        // Add user's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Add tweets of people user follows
        for (int user : following[userId]) {

            for (auto tweet : tweets[user]) {
                pq.push(tweet);
            }
        }

        // Get the 10 most recent tweets
        while (!pq.empty() && ans.size() < 10) {

            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
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