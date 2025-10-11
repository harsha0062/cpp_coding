#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

// Router class definition as provided
class Router {
public:
    int limit = 0; // Memory limit for router
    set<vector<int>> packets; // Stores unique packets {source, destination, timestamp}
    unordered_map<int, int> rp; // Number of packets forwarded per destination
    unordered_map<int, vector<int>> pd; // List of timestamps per destination
    queue<vector<int>> q; // Queue for packets

    // Constructor to set memory limit
    Router(int memoryLimit) { limit = memoryLimit; }

    // Adds a packet to the router. Returns true if added, false if already exists.
    bool addPacket(int source, int destination, int timestamp) {
        // If packet already exists, don't add again
        if (packets.find({source, destination, timestamp}) != packets.end())
            return false;
        // If router memory is full, remove oldest packet
        if (q.size() > 0) {
            if (limit == q.size()) {
                vector<int> p = q.front();
                packets.erase(p);
                rp[p[1]]++;
                q.pop();
            }
        }
        // Add the new packet
        q.push({source, destination, timestamp});
        pd[destination].push_back(timestamp);
        packets.insert({source, destination, timestamp});
        return true;
    }

    // Forwards the next packet. Returns the packet details, or empty if none.
    vector<int> forwardPacket() {
        if (q.size() > 0) {
            vector<int> p = q.front();
            packets.erase(p);
            rp[p[1]]++;
            q.pop();
            return p;
        }
        return {};
    }

    // Gets the count of packets for a destination between startTime and endTime
    int getCount(int destination, int startTime, int endTime) {
        if (pd.find(destination) == pd.end())
            return 0;

        int x = rp[destination];
        auto it = lower_bound(pd[destination].begin() + x,
                              pd[destination].end(), startTime);
        auto it2 = upper_bound(pd[destination].begin() + x,
                               pd[destination].end(), endTime);
        int count = int(it2 - it);
        return count;
    }
};

int main() {
    // Create a router with memory limit 3
    Router* router = new Router(3);

    // Test: Add packets
    cout << "AddPacket(1, 2, 100): " << router->addPacket(1, 2, 100) << endl; // Should return true
    cout << "AddPacket(1, 2, 101): " << router->addPacket(1, 2, 101) << endl; // Should return true
    cout << "AddPacket(2, 3, 102): " << router->addPacket(2, 3, 102) << endl; // Should return true
    cout << "AddPacket(1, 2, 100): " << router->addPacket(1, 2, 100) << endl; // Should return false (duplicate)
    cout << "AddPacket(3, 2, 103): " << router->addPacket(3, 2, 103) << endl; // Should cause oldest packet to be removed

    // Test: Forward packets
    vector<int> forwarded = router->forwardPacket();
    if (!forwarded.empty()) {
        cout << "Forwarded Packet: ";
        for (int val : forwarded) cout << val << " ";
        cout << endl;
    } else {
        cout << "No packet to forward" << endl;
    }

    // Test: Get count of packets sent to destination 2 from time 99 to 104
    int count = router->getCount(2, 99, 104);
    cout << "Packet count for destination 2 between 99 and 104: " << count << endl;

    // Test: Get count for destination 3
    count = router->getCount(3, 100, 105);
    cout << "Packet count for destination 3 between 100 and 105: " << count << endl;

    delete router;
    return 0;
}
