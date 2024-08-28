#include<bits/stdc++.h>
using namespace std;
class ConsistentHashingRing{
    private:
    map<int,string>ring;
    set<int>keys;
    int replicas;
    int getHash(const string &x){
        hash<string>hash_function;
        return hash_function(x);
    }
    public:
    ConsistentHashingRing(int x): replicas(x){};

    void addNode(const string &node){
        for(int i=0;i<replicas;i++){
            int replica_key=getHash(node+"_"+to_string(i));
            keys.insert(replica_key);
            ring[replica_key]=node;
        }
    }
    void removeNode(const string &node){
        for(int i=0;i<replicas;i++){
            int replica_key=getHash(node+"_"+to_string(i));
            keys.erase(replica_key);
            ring.erase(replica_key);
        }
    }
    string getNode(const string &req){
        int hashedValue=getHash(req);
        cout<<"Hash Value of the request is :"<<hashedValue<<"\n";
        if(ring.empty())return "";
        auto it=keys.lower_bound(hashedValue);
        if(it==keys.end()){
            it=keys.begin();
        }
        return ring[*it];
    }
    void print_ring() {
            cout << "Current state of the Consistent Hash Ring:" << endl;
            for (const auto& [x,y]: ring) {
                cout << "Hash: " << x << " -> Node: " << y << endl;
            }
            cout << endl;
        }
};
int main(){
    ConsistentHashingRing hash_ring(5);
    // Add nodes to the ring
    hash_ring.addNode("Node_A");
    hash_ring.addNode("Node_B");
    hash_ring.addNode("Node_C");
    hash_ring.addNode("Node_D");
    // Get the node for a key
    string key = "seond_key";
    string node = hash_ring.getNode(key);

    cout << "The key '" << key << "' is mapped to node: " << node << endl;
    hash_ring.print_ring();
    return 0;
}
