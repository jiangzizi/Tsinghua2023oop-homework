class Altset {
public:
    Altset()
    {
        gene=new bool [100];
    }
    ~Altset()
    {
        delete []gene;
    }
    bool *gene;
    int length;
    int sum=0;
    int nowlen=100;
    Altset(const char *data, int len);
	Altset& operator = (const Altset &altset)
    {
        sum=altset.sum;
        nowlen=altset.nowlen;
        this->gene=new bool [nowlen];
        for(int i=0;i<altset.length;i++)
        {
            this->gene[i]=altset.gene[i];
        }
        this->length=altset.length;
        return *this;
    }
    Altset& operator = (Altset &&altset)
    {
        sum=altset.sum;
        nowlen=altset.nowlen;
        altset.nowlen=0;
        altset.sum=0;
        this->gene=altset.gene;
        this->length=altset.length;
        altset.length=0;
        altset.gene=nullptr;
        return *this;
    }

    void inverse(int index);
    void append(int value);
    bool get(int index) const;
    bool empty() const;
    int count() const;
};
