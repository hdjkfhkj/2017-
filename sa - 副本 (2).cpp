#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define inf 1000000000
#define l 50
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <time.h>
#define random(x) (rand()%x)
struct node{
    int a;//adj
    int b;//self
    int left;
    int p;
    int number;//order
    //int type;//b
};
struct snode
{
    int ne;
    int id;
};
snode need[1510];
int depth=0,last=inf;
vector<node> path,bp;
vector<node> g[1510],bg[1510],bgb[1510],gp[1510];
vector<int> ans,best,ser,lser,current;
int ht[1010]={0},cn[1010]={0};
int bcost=inf,lcost=inf;
int visited[1510]={0};
int k,cost,n,m,s,d;;
void init1()
{
    for(int i=0;i<1010;++i){
        ht[i]=0;
    }
    for(int i=0; i<1510; ++i)
    {
        gp[i].clear();
    }
    for(int i=0;i<k;++i){
        ht[ans[i]]=1;
    }
    while(ans.size()>k){
        ans.pop_back();
    }
    for(int i=0;i<1510;++i){
        g[i]=bgb[i];
    }
}
bool cmp(snode a,snode b)
{
    return a.ne>b.ne;
}
void init(){
    for(int i=0;i<1510;++i){
        visited[i]=0;
    }
}
int atoi(string s){
    int ans=0;
    for(int i=0;i<s.size();++i){
        ans=ans*10+s[i]-'0';
    }
    return ans;
}
void dfs(int v,int t)
{
  //  cout<<v<<" "<<ht[v]<<" "<<depth<<endl;
    if(depth>t||depth>last)
    {
       // cout<<"hjnhnjh "<<bp.size()<<endl;
        return;
    }
    if(ht[v]==1)
    {
  //  cout<<v<<endl;
        if(depth<last)
        {
           //  cout<<depth<<"aaaaaaaaaaaaahjnhnjh "<<last<<" "<<v<<endl;
            bp=path;
            last=depth;
        }
    }
    for(int i=0; i<g[v].size(); ++i)
    {
        if(visited[g[v][i].a]==0&&g[v][i].left>0)
        {
            visited[g[v][i].a]=1;
            depth+=g[v][i].p;
            g[v][i].number=i;
            g[v][i].b=v;
            path.push_back(g[v][i]);
            dfs(g[v][i].a,t);
            depth-=g[v][i].p;
            visited[g[v][i].a]=0;
            path.pop_back();
        }
    }
}
void deploy(){
    cost=k*m;
    int num=0;
    for(int ee=n; ee<n+s; ++ee) //assign path for snode
    {
        int t=m*1.00/need[ee].ne;//threshold
        int i=need[ee].id;
        int ccost=0;
         for(int i=0;i<1510;++i){
        bg[i]=g[i];
    }
        while(g[i][0].left>0)
        {
            num++;
            depth=0;
            last=inf;
            init();
            bp.clear();
            path.clear();
            t=(m-ccost)/g[i][0].left;
            dfs(i,t);
            int mini=g[i][0].left;
            int up=0;
            if(bp.size()==0){
                for(int j=gp[i].size()-1; j>=0; --j)
        {
                  int v=gp[i][j].b;
                int u=gp[i][j].number;
                if(v!=i)
                g[v][u].left=bg[v][u].left;
        }
        gp[i].clear();
        g[i][0]=bg[i][0];//restore
          gp[i].push_back(g[i][0]);
            g[i][0].left=0;
            cost+=m;
            cost-=ccost;
            ccost=0;
            ht[g[i][0].a]=1;
            ans.push_back(g[i][0].a);
         }
         else{
            for(int j=0; j<bp.size(); ++j)
            {
                if(bp[j].left<mini)
                {
                    mini=bp[j].left;
                }
                up+=bp[j].p;
            }
          node current;
          current.a=g[i][0].a;
          current.b=g[i][0].b;
          current.left=mini;
            gp[i].push_back(current);
            for(int j=0; j<bp.size(); ++j)
            {
                int v=bp[j].b;
                int u=bp[j].number;
                if(v!=i)
                g[v][u].left-=mini;
            if(v!=i)
                gp[i].push_back(bp[j]);
            }
            cost+=mini*up;
            ccost+=mini*up;
            g[i][0].left-=mini;
         }
        }
    }
    if(cost<bcost){
        bcost=cost;
        best=ans;
    }
}
void deploy1(){
    cost=best.size()*m;
    cout<<cost<<endl;
    int num=0;
    for(int ee=n; ee<n+s; ++ee) //assign path for snode
    {
        int t=m*1.00/need[ee].ne;//threshold
        int i=need[ee].id;
        int ccost=0;
         for(int i=0;i<1510;++i){
        bg[i]=g[i];
    }
        while(g[i][0].left>0)
        {
            num++;
            depth=0;
            last=inf;
            init();
            bp.clear();
            path.clear();
            t=(m-ccost)/g[i][0].left;
            dfs(i,t);
            int mini=g[i][0].left;
            int up=0;
            for(int j=0; j<bp.size(); ++j)
            {
                if(bp[j].left<mini)
                {
                    mini=bp[j].left;
                }
                up+=bp[j].p;
            }
          node current;
          current.a=g[i][0].a;
          current.b=g[i][0].b;
          current.left=mini;
            gp[i].push_back(current);
            for(int j=0; j<bp.size(); ++j)
            {
                int v=bp[j].b;
                int u=bp[j].number;
                if(v!=i)
                g[v][u].left-=mini;
            if(v!=i)
                gp[i].push_back(bp[j]);
            }
            cost+=mini*up;
            ccost+=mini*up;
            g[i][0].left-=mini;
         }
        }
}
void print(){
    for(int i=n; i<n+s; ++i)
    {
        for(int j=gp[i].size()-1; j>=0; --j)
        {
            if(gp[i][j].b==i)
            {
                printf("%d %d %d\n",gp[i][j].a,gp[i][j].b-n,gp[i][j].left);
            }
            else
            {
                printf("%d ",gp[i][j].a);
            }
        }
    }
}
int main(){
    node c1,c2;
    string x="",y="",z="",w="";
    ifstream infile;
    char buf[1024]={0};
    infile.open("F:\\0.txt");
    if(infile.is_open())
    {
        while(infile.good() && !infile.eof())
        {
            infile.getline(buf,1024);
            stringstream word(buf);
            word >> x;
            word >> y;
            word >> z;
            n=atoi(x);
            d=atoi(y);
            s=atoi(z);
            infile.getline(buf,1024);
            infile.getline(buf,1024);
            stringstream word2(buf);
            word2 >> x;
            m=atoi(x);
            infile.getline(buf,1024);
int o,p,q,r;
            for(int i=0; i<d; ++i)
            {
                infile.getline(buf,1024);
                stringstream word3(buf);
                word3 >> x;
                word3 >> y;
                word3 >> z;
                word3 >> w;
                o=atoi(x);
                p=atoi(y);
                q=atoi(z);
                r=atoi(w);
                c1.a=o;
                c2.a=p;
                c1.b=p;
                c2.b=o;
                c1.left=c2.left=q;
              //  cout<<q<<endl;
                c1.p=c2.p=r;
                g[o].push_back(c2);
                g[p].push_back(c1);
            }
            infile.getline(buf,1024);
            for(int i=n; i<n+s; ++i)
            {
                infile.getline(buf,1024);
                stringstream word4(buf);
                word4 >> x;
                word4 >> y;
                word4 >> z;
                o=atoi(x);
                p=atoi(y);
                q=atoi(z);
                o=o+n;
                need[o].ne=q;
                need[o].id=o;
                c1.a=o;
                c2.a=p;
                c1.b=p;
                c2.b=o;
                c1.left=c2.left=q;
                c1.p=c2.p=0;
               cn[p]=1;
                g[o].push_back(c2);
                g[p].push_back(c1);
                ser.push_back(p);
            }
            infile.getline(buf,1024);
        }
        infile.close();
    }
    for(int i=0;i<1510;++i){
        bgb[i]=g[i];
    }
      sort(need+n,need+n+s,cmp);
    if(s<100){
        k=s/3;
    }
    double tf=0.01,t=100;
    int newc;
    int change=0,sc=0;
    srand((unsigned)time(NULL));
    int server=rand();
    server=server%n;
    for(int i=0;i<k;++i){//initial
            while(ht[server]==1)
            server=rand();
    server=server%n;
        ans.push_back(server);
        ht[server]=1;
    }
    deploy();
    lcost=cost;
    lser=ans;
    while(t>tf){
        sc=0;
        for(int i=0;i<100;++i){
            change=0;
            int u,v;
            srand((unsigned)time(NULL));
            u=rand();
             u=ser[u%s];
               //cout<<change<<endl;
            while(ht[u]==1){
                u=rand();
                u=ser[u%s];
            }
            v=rand()%k;
                ht[ans[v]]=0;
                ans[v]=u;
                ht[u]=1;
                //cost=k*m;
                init1();
                deploy();
                newc=cost;
                current=ans;
                int dif=newc-lcost;
                if(dif<=0){
                    lcost=newc;
                    lser=current;
                    change=1;
                }
                else{
                     if(exp(-dif/t)>rand()%100/100.00){
                lcost=newc;
                    lser=current;
                    change=1;
            }
                }
                if(change==0){
                    ans=lser;
                    s++;
                }
                else{
        sc=0;
    }
    if(sc==2){
        break;
    }
     // cout<<change<<endl;
    init1();
      cout<<change<<endl;
    }
    t=0.9*t;
    cout<<t<<endl;
    }
      cout<<change<<endl;
    cout<<k<<endl;
    cout<<bcost<<" "<<best.size()<<endl;
    cout<<cost<<" "<<ans.size()<<endl;
    for(int i=0;i<1510;++i){
        ht[i]=0;
    }
    for(int i=0;i<best.size();++i){
        ht[best[i]]=1;
        cout<<best[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<1510;++i){
        if(ht[i]==1){
            cout<<i<<endl;
        }
    }
  //  cost=best.size()*m;
    deploy1();
    cout<<endl;
    cout<<endl;
     for(int i=0;i<1510;++i){
        if(ht[i]==1){
            cout<<i<<endl;
        }
    }
    print();
     cout<<cost<<" "<<bcost<<endl;
    return 0;
        }
