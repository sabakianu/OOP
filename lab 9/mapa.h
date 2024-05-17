#pragma once
template<typename key, typename value>
class nod
{
public:
    key cheie;
    value valoare;
    int index;
public:
    nod() {};
    nod& operator=(nod& ceva)
    {
        this->index = ceva.index;
        this->cheie = ceva.cheie;
        this->valoare = ceva.valoare;
        return (*this);
    }
    bool operator==(nod& ceva)
    {
       // if (this->index != ceva.index)
        //    return false;
        if (this->cheie != ceva.cheie)
            return false;
        if (this->valoare != ceva.valoare)
            return false;
        return true;
    }
};
template<typename key, typename value>
class Map
{
private:
    nod<key, value>* x;
    int length;
    int indexe = 0;
public:
    Map()
    {
        length = 0;
        x = new nod<key, value>[100];
    };
    ~Map()
    {
        delete[] x;
    };
    value& operator[](key t)
    {
        for (int i = 0; i < length; i++)
            if (x[i].cheie == t)
            {
                return x[i].valoare;
            }
        length++;
        x[length - 1].cheie = t;
        x[length - 1].index = indexe;
        indexe++;
        return x[length - 1].valoare;
    }
    void Set(key t, value z)
    {
        int ok = 0;
        for (int i = 0; i < length; i++)
        {
            if (x[i].valoare == z)
            {
                ok = 1;
                x[i].cheie = t;
            }
        }
        if (ok == 0)
        {
            length++;
            x[length - 1].cheie = t;
        }
    }
    int Count()
    {
        return this->length;
    }
    void Clear()
    {
        this->length = 0;
        delete[] this->x;
        x = new nod<key, value>[100];
    }
    bool Get(const key& k, value& val)
    {
        value temp;
        int ok = 0;
        for (int i = 0; i < length; i++)
        {
            if (k == x[i].cheie)
            {
                ok = 1;
                temp = x[i].valoare;
            }
        }
        if (ok == 0)
            return false;
        else
        {
            val = temp;
            return true;
        }
    }
    bool Delete(const key& k)
    {
        bool ok = false;
        int indextemp;
        for (int i = 0; i < length; i++)
        {
            if (key == k)
            {
                indextemp = this->x[i].index;
                ok = true;
                for (int j = i; j << length - 1; j++)
                    x[j] = x[j] + 1;
            }
            if (ok == true)
                break;
        }
        if (ok == true)
        {

            length--;
            for (int i = 0; i < length; i++)
                if (this->x[i].index > indextemp)
                    this->x[i].index--;
        }
        return ok;
    }
    bool Includes(const Map<key, value>& map)
    {
        for (int i = 0; i < this->length; i++)
        {
            bool ok = false;
            for(int j=0;j<map.length;j++)
                if (this->x[i] == map.x[j])
                {
                    ok = true;
                    break;
                }
            if (ok == false)
                return false;
        }
        return true;
    }
    class Iterator
    {
    private:
        nod<key, value>* current;
        int index;

    public:
        Iterator(nod<key, value>* ptr, int idx) : current(ptr), index(idx) {}

        bool operator!=(const Iterator& other) const
        {
            return current != other.current;
        }

        void operator++()
        {
            ++current;
            ++index;
        }

        nod<key, value>& operator*() const
        {
            return *current;
        }

        nod<key, value>* operator->() const
        {
            return current;
        }
    };

    Iterator begin()
    {
        return Iterator(x, 0);
    }

    Iterator end()
    {
        return Iterator(x + length, length);
    }
};