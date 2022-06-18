class WordFilter {
public:
    struct Trie
    {
        Trie *children[27];
        bool isEnd;
        int index;
        Trie() 
        {
            for(int i=0;i<27;i++)
                children[i]=NULL;
            isEnd=false;
            index=-1;
        }
    };
    Trie *root=new Trie();
    void insert(string word,int pos) 
    {
        Trie *p=root;
        for(auto c:word)
        {
            if(!p->children[c-'a'])
            {
                p->children[c-'a']=new Trie();
            }
            p->index=pos;
            p=p->children[c-'a'];
        }
        p->index=pos;
        p->isEnd=true;
    }
    WordFilter(vector<string>& words) 
    {
        for(int k=0;k<words.size();k++)
        {
            string s=words[k],t;
            t=s;
            s="{"+s;
            insert(s,k);
            for(int i=t.size()-1;i>=0;i--)
            {
                s=t[i]+s;
                insert(s,k);
            }
        }
    }
    int search(string s)
    {
        Trie *p=root;
        for(int i=0;i<s.size();i++)
        {
            if(p->children[s[i]-'a']==NULL)
                return -1;
            p=p->children[s[i]-'a'];
        }
        return p->index;
    }
    int f(string prefix, string suffix) 
    {
        suffix+="{"+prefix;
        return search(suffix);
    }
};