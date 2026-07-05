class LRUCache {
public:
list<int>dll;
map<int,pair<list<int>::iterator,int>>mp;
int n;
    LRUCache(int capacity) {
    n=capacity;
            }      
            void makerecentlyused(int key){
                dll.erase(mp[key].first);
                dll.push_front(key);
                mp[key].first=dll.begin();
            }
    
    int get(int key) {
       if(mp.find(key)==mp.end()){
        return -1;
       }
       makerecentlyused(key);
       return mp[key].second;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
              mp[key].second=value;
           makerecentlyused(key);
        }
        else{
            dll.push_front(key);
            mp[key].first=dll.begin();
            mp[key].second=value;
            n--;
        }
        if(n<0){
           mp.erase(dll.back());
           dll.pop_back();
           n++;
        }       
    }
};
