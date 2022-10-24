//ya no list only pointer manip beats 99.96 percent runtime as well as 99.04 memory usage
//also tle is fixed 
class LRUCache {
public:
    struct Node{
        Node(Node* prev , Node * next, int value,int key):s_prev(prev),s_next(next),s_value(value),s_key(key){}
        int s_value;
        int s_key;
        Node * s_next;
        Node * s_prev;
        
    };
    LRUCache(int capacity):m_capacity(capacity),m_key_val(),m_lru(nullptr),m_mru(nullptr){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    }
    
    int get(int key) {
        
        
        if(m_key_val.find(key) != m_key_val.end()){
            Node * elm =  m_key_val[key];
            
              if(m_mru != m_lru){
                      if(m_mru != m_key_val[key]){
                          if(elm->s_prev == nullptr){
                              m_lru = m_lru->s_next;
                              m_lru->s_prev = nullptr;
                          }
                          else{
                              elm->s_prev->s_next = elm->s_next;
                              elm->s_next->s_prev = elm->s_prev;
                              }
                              m_mru->s_next = elm;
                              elm->s_prev = m_mru;
                              m_mru = elm;
                              elm->s_next = nullptr;

                      }
                
               }
            return m_mru->s_value;
        }
        else
            return -1;
        
        
        
      
    }
    
    void put(int key, int value) {
        
        if(m_key_val.find(key) != m_key_val.end()){
            m_key_val[key]->s_value = value;
            Node * elm =  m_key_val[key];
            
              if(m_mru != m_lru){
                      if(m_mru != m_key_val[key]){
                          if(elm->s_prev == nullptr){
                              m_lru = m_lru->s_next;
                              m_lru->s_prev = nullptr;
                          }
                          else{
                              elm->s_prev->s_next = elm->s_next;
                              elm->s_next->s_prev = elm->s_prev;
                              }
                              m_mru->s_next = elm;
                              elm->s_prev = m_mru;
                              m_mru = elm;
                              elm->s_next = nullptr;

                      }
                
               }
        }
        else if(m_capacity > 0){
            Node * nPtr = new Node(nullptr,nullptr,value,key);
            m_key_val[key] = nPtr;
            if(m_mru == nullptr && m_lru == nullptr){
                m_mru = nPtr;
                m_lru = nPtr;
            }
            else{
                m_mru->s_next = nPtr;
                nPtr->s_prev = m_mru;
                m_mru = nPtr;
            }
           m_capacity--;
       }
       else{ //eviction
            m_key_val.erase(m_lru->s_key);
           if(m_mru == m_lru){
              
               m_lru->s_key = key;
               m_lru->s_value = value;
               m_key_val[key] = m_lru;
           }
           else{
               Node* temp = m_lru;
               m_lru=m_lru->s_next;
               m_lru->s_prev = nullptr;
               m_mru->s_next = temp;
               temp->s_prev  = m_mru;
               m_mru = temp;
               m_mru->s_next = nullptr;
               m_key_val[key] = temp;
               temp->s_key = key;
               temp->s_value = value;
           }
           
           
       }
        
    }
    int m_capacity;
    unordered_map<int,Node*>m_key_val;
    Node * m_lru;
    Node * m_mru;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
