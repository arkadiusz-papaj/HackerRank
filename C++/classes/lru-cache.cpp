//implement LRUCache
class LRUCache : public Cache {
    public:
    LRUCache() {
        mp = map<int,Node*>{};
        cp = 0;
        tail = nullptr;
        head = nullptr;
    };

    explicit LRUCache(int capacity): LRUCache() {
        cp = capacity;
    };

    LRUCache(LRUCache const& lru) = delete;
    LRUCache(LRUCache && lru) = delete;
    LRUCache & operator=(LRUCache const& lru) = delete;
    LRUCache & operator=(LRUCache && lru) = delete;

    virtual ~LRUCache(){
        while (tail != nullptr) {
            auto* to_delete = tail;
            tail = tail->prev;
            delete to_delete;
        };
    };

    void set(int key, int value) override {
        auto found = mp.find(key);

        if (found != mp.end()) {
            auto* node_found = found->second;
            node_found->value = value;
            auto* node_before = node_found->prev;
            auto* node_after = node_found->next;

            if (node_before == nullptr) {
                //head was found
            }
            else if (node_after == nullptr) {
                //tail was found
                node_before->next = nullptr;
                
                attachFront(node_found);
            }
            else { //middle
                node_before->next = node_after;
                node_after->prev = node_before;

                attachFront(node_found);
            }

        }
        else {
            auto* new_node = new Node{key, value};

            if (mp.size() < cp) {
                mp.insert({key, new_node});
                if (head != nullptr) {
                    attachFront(new_node);
                }
                else {
                    head = new_node;
                    tail = new_node;
                }
            }
            else {
                removeLast();
                mp.insert({key, new_node});
                attachFront(new_node);
            }

            new_node = nullptr;
        }

    };

    int get(int key) override {
        auto found = mp.find(key);
        if (found != mp.end()) {
            return found->second->value;
        }
        else {
            return -1;
        }
    };

    private:
    void attachFront(Node* node) {
        node->prev = nullptr;
        node->next = head;

        head->prev = node;
        head = node;
    };

    void removeLast() {
        auto key_to_remove = tail->key;

        tail = tail->prev;
        tail->next = nullptr;

        delete mp.find(key_to_remove)->second;
        mp.erase(key_to_remove);
    };
};