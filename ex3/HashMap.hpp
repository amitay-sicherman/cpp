//
// Created by asicherm on 1/13/2020.
//

#ifndef CPP3_HashMap_HPP
#define CPP3_HashMap_HPP

#include<iostream>
#include <list>
#include <vector>
#include <stdexcept>

#define START_CAPACITY 16
#define MAX_LOAD_FACTOR 0.75
#define MIN_LOAD_FACTOR 0.25

using namespace std;

template <typename KeyT, typename ValueT>
class HashMapNode
{
public:
    pair<KeyT,ValueT>* _data;
    HashMapNode* _next;
    HashMapNode* _prev;
    explicit HashMapNode(pair<KeyT,ValueT>* data= nullptr):_data(data),_next(nullptr),_prev(nullptr){}
};

template <typename KeyType, typename ValueType>
class HashMap
{
    int _capacity ;
    int _size;
    double _loadFactor;
    vector<vector<HashMapNode<KeyType,ValueType>*>> *_table;
    HashMapNode<KeyType,ValueType>* _firstNode;
    HashMapNode<KeyType,ValueType>* _lastNode;

public:
    HashMap()
    {
        _capacity=START_CAPACITY;
        _table=new vector<vector<HashMapNode<KeyType,ValueType>*>>(_capacity);
        _size=0;
        _loadFactor=0.0;
        _firstNode= nullptr;
        _lastNode= nullptr;
    }
    HashMap(vector<KeyType> keys,vector<ValueType> values,int cap=START_CAPACITY)
    {
        if (keys.size()!=values.size())
        {
            //todo: exption not work
            throw invalid_argument( "key and value size not much");
        }
        _capacity=cap;
        _table=new vector<vector<HashMapNode<KeyType,ValueType>*>>(_capacity);
        _size=0;
        _loadFactor=0.0;
        _firstNode= nullptr;
        _lastNode= nullptr;
        insetVectors(keys,values);
    }
    ~HashMap()
    {
        clear();
    }
    void insetVectors(vector<KeyType> keys, vector<ValueType> values)
    {
        for (int  i=0; i<(int)keys.size();++i)
        {
            this->insert(keys.at(i),values.at(i));
        }
    }

    class iterator{
    private:
        HashMapNode<KeyType,ValueType>* _pointer;

    public:
        iterator(HashMapNode<KeyType,ValueType>* p = nullptr):_pointer(p){}
        pair<KeyType,ValueType>& operator*()const {return *(_pointer->_data);}
        pair<KeyType,ValueType>*operator->() const { return _pointer->_data; }
        iterator& operator++()
        {
            _pointer=_pointer->_next;
            return *this;
        }
        iterator& operator++(int)
        {
            iterator tmp=*this;
            _pointer=_pointer->_next;
            return tmp;
        }
        bool operator==(iterator const& athP)const{
            return athP._pointer==this->_pointer;
        }
        bool operator!=(iterator const& athP){
            return athP._pointer!=this->_pointer;
        }
    };
    //todo: chege ret rot const
    iterator cbegin()
    {
        return iterator(_firstNode);
    }
    //todo: chege ret rot const
    iterator cend()
    {
        return iterator(nullptr);
    }
    iterator begin()
    {
        return iterator(_firstNode);
    }
    iterator end()
    {
        return iterator(nullptr);
    }
    int size()const {return _size;}
    int capacity() const {return _capacity;}
    bool empty() const {return _size==0;}
    double getLoadFactor() const {return _loadFactor;}
    void reHash(int newCap)
    {
        vector<KeyType> keys(0);
        vector<ValueType> vals(0);
        HashMapNode<KeyType,ValueType>* current=_firstNode;
        while(current != nullptr)
        {
            keys.push_back(current->_data->first);
            vals.push_back(current->_data->second);
            current=current->_next;
        }
        clear();
        _capacity=newCap;
        _table=new vector<vector<HashMapNode<KeyType,ValueType>*>>(_capacity);
        insetVectors(keys,vals);
    }


    bool insert(KeyType key,ValueType val)
    {
        if (containsKey(key))
        {
            //todo:change to reKey
            erase(key);
        }
        auto temp=new pair<KeyType,ValueType> (key,val);
        auto item=new HashMapNode<KeyType,ValueType>(temp);
        int index = HashFunction(item->_data->first);
        _table->at(index).push_back(item);

        if(_firstNode== nullptr)
        {
            _firstNode=item;
            _lastNode=item;
        }
        else
        {
            _lastNode->_next=item;
            item->_prev=_lastNode;
            _lastNode=item;
        }

        _size++;
        if (_loadFactor>=MAX_LOAD_FACTOR)
        {
            reHash(_capacity*2);
        }
        _loadFactor=double (_size)/_capacity;
        return true;
    }

    bool containsKey(KeyType key)
    {
        int index = HashFunction(key);
        for(HashMapNode<KeyType,ValueType>* single : _table->at(index))
        {
            if ( single->_data->first==key)
            {
                return true;
            }
        }
        return false;
    }
    bool erase(KeyType key)
    {
        int index = HashFunction(key);
        int counter=0, deleteIndex=-1;
        for(HashMapNode<KeyType,ValueType>* single : _table->at(index))
        {
            if ( single->_data->first==key)
            {
                deleteIndex=counter;
                break;
            }
            counter++;
        }
        if (deleteIndex!=-1)
        {
            _table->at(index).at(deleteIndex);
            HashMapNode<KeyType,ValueType>* prev_=_table->at(index).at(deleteIndex)->_prev;
            HashMapNode<KeyType,ValueType>* next_=_table->at(index).at(deleteIndex)->_next;
            if (prev_ == nullptr && next_== nullptr)
            {
                    _firstNode=_lastNode= nullptr;
            }
            else if (prev_== nullptr)
            {
                _firstNode=next_;
            }
            else if (next_== nullptr)
            {
                _lastNode=prev_;
            }
            else
            {
                prev_->_next=next_;
                next_->_prev=prev_;
            }
            _table->at(index).at(deleteIndex)->_next=_table->at(index).at(deleteIndex)->_prev= nullptr;
            vector<HashMapNode<KeyType,ValueType>*>&temp=_table->at(index);
            temp.erase(temp.begin()+counter);
            _size--;
            _loadFactor=double (_size)/_capacity;
            if(_loadFactor<MIN_LOAD_FACTOR)
            {
                reHash(_capacity/2);
            }
            return true;
        }
        return false;

    }

    ValueType at(KeyType key)
    {
        int index = HashFunction(key);
        for(HashMapNode<KeyType,ValueType>* single : _table->at(index))
        {
            if ( single->_data->first==key)
            {
                return single->_data->second;
            }
        }
        //todo: exption not work
        throw invalid_argument( "key not found" );
    }

    int bucketSize(KeyType key)
    {
        if (!containsKey(key))
        {
            //todo: exption not work
            throw invalid_argument( "key not found" );
        }
        int index=HashFunction(key);
        return _table->at(index).size();
    }

    int bucketIndex(KeyType key)
    {
        if (!containsKey(key))
        {
            //todo: exption not work
            throw invalid_argument( "key not found" );
        }
        return(HashFunction(key));
    }

    void clear()
    {
        for (int i = 0; i < _capacity; i++)
        {
            vector<HashMapNode<KeyType,ValueType>*>& vec=_table->at(i);

            for(HashMapNode<KeyType,ValueType>* HashMapNodeTemp:vec)
            {
                delete HashMapNodeTemp->_data;
                delete HashMapNodeTemp;
            }
            vec.clear();

        }
        delete _table;
        _capacity=16;
        _table=new vector<vector<HashMapNode<KeyType,ValueType>*>>(_capacity);

        _size=0;
        _loadFactor=0;
        _firstNode= nullptr;
        _lastNode= nullptr;

    }
    HashMap& operator=(ValueType val)
    {
        for (int i = 0; i < _capacity; i++)
        {
            int j;
            vector<HashMapNode<KeyType,ValueType>*>& tempV=(*_table)[i];
            for (j=0;j<(*_table)[i].size();++j)
            {
                HashMapNode<KeyType,ValueType>* tempP = tempV[j];
                tempP->_data->second= val;
            }
        }
    }

    ValueType operator[](KeyType key)
    {
        int index = HashFunction(key);
        for(HashMapNode<KeyType,ValueType>* single : _table->at(index))
        {
            if ( single->_data->first==key)
            {
                return single->_data->second;
            }
        }
        //todo: add [] for table[x]=y

    }
    bool operator==(HashMap other) {
        for (auto p : other)
        {
            if (!(containsKey(p.first) && at(p.first)==p.second))
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(HashMap const & other)
    {
        return !(this==other);
    }
    int HashFunction(KeyType x) {
        return (std::hash<KeyType>{}(x) & (_capacity-1));
    }


    void displayHash()
    {
        cout<<"size:"<<size()<<" cap:"<<capacity()<<" empty:"<<empty()<<"factor:"<<getLoadFactor()<<endl;
        for (int i = 0; i < _capacity; i++)
        {
            int j;
            for (j=0;j<(*_table)[i].size();++j)
            {
                vector<HashMapNode<KeyType,ValueType>*> b=(*_table)[i];
                HashMapNode<KeyType,ValueType>* cc=b[j];
                pair<KeyType,ValueType>* c=cc->_data;
                KeyType key=c->first;
                ValueType val=c->second;
                cout<<i<<":("<<key<<","<<val<<")"<<endl ;
            }
        }
        cout<<endl<<endl;

    }
};








#endif //CPP3_HashMAP_HPP
// 'std::vector<HashMap<int, int>::HashMapNode<KeyType,ValueType>, std::allocator<HashMap<int, int>::HashMapNode<KeyType,ValueType>> >*'
// 'std::vector<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >, std::allocator<std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > > > >*' in assignment
