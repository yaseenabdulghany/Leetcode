class Solution {
public:
    vector<int> siz,p;
    void initialise(int n){
        siz.resize(n,1);
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
        }
    }
    int findp(int a){
        if(p[a]==a) return p[a];
        return p[a]=findp(p[a]);
    }
    void uni(int a,int b){
        a=findp(a);
        b=findp(b);
        if(a!=b){
            if(siz[b]>siz[a]){
                swap(a,b);
            }
            p[b]=a;
            siz[a]+=siz[b];
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<int> es(n,0);
        initialise(n);
        for(int i=0;i<e.size();i++){
            if(findp(e[i][0])!=findp(e[i][1])){
                int x=es[findp(e[i][0])];
                int y=es[findp(e[i][1])];
                uni(e[i][0],e[i][1]);
                es[findp(e[i][0])]=x+y+1;
            }
            else{
                es[findp(e[i][0])]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==p[i]){
                if((siz[i]*(siz[i]-1)/2)==es[p[i]])ans++;
            }
        }
        return ans;
    }
};