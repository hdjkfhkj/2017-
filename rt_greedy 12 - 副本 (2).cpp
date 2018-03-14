/*28 44 12

100

0 1 20 1
0 2 16 1
0 3 13 1
0 6 13 2
0 7 25 2
0 8 36 2
0 9 14 2
0 16 8 2
0 26 13 2
1 2 5 2
1 3 11 1
1 15 16 2
1 16 24 2
1 18 31 2
1 19 26 2
2 3 7 1
2 4 37 2
2 20 2 2
2 21 5 2
2 25 24 2
3 19 24 2
3 24 17 2
4 5 26 1
4 6 12 1
5 6 14 1
8 21 36 5
9 10 6 1
9 11 14 1
10 11 9 1
10 26 11 5
12 13 15 1
12 14 9 1
12 15 12 1
13 15 27 1
13 14 11 1
14 15 19 1
17 18 22 1
21 22 22 1
21 23 18 1
21 24 14 1
22 23 23 1
22 24 11 1
23 24 23 1
26 27 19 1

0 8 40
1 11 13
2 22 28
3 3 45
4 17 11
5 19 26
6 16 15
7 13 13
8 5 18
9 25 15
10 7 10
11 24 23  */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#define inf 1000000000
using namespace std;
struct node
{
    int a;//adj vetex
    int b;
    int left;
    int p;
    int number;
};//network nodes
struct snode
{
    int ne;
    int id;
};
vector<node> g[1510],bg[1510],bgb[1510];
int ht[1010]= {0};
snode need[1510];
int n;
int depth=0,last=inf;
int visited[1510]= {0};
vector<node> path,bp;
vector<node> gp[1510],bgp[1510];
int ct[1010]={0};
int atoi(string s){
    int ans=0;
    for(int i=0;i<s.size();++i){
        ans=ans*10+s[i]-'0';
    }
    return ans;
}
void init()
{
    for(int i=0; i<1510; ++i)
    {
        visited[i]=0;
    }
}
bool cmp(snode a,snode b)
{
    return a.ne>b.ne;
}
void dfsbg(int v,int t)
{
  //  cout<<v<<" "<<ht[v]<<" "<<depth<<endl;
    if(depth>t||depth>last)
    {
       // cout<<"hjnhnjh "<<bp.size()<<endl;
        return;
    }
    if(ht[v]==1)
    {
    //    cout<<"hgjjeeeeeeee"<<endl;
        if(depth<last)
        {
           //  cout<<depth<<"aaaaaaaaaaaaahjnhnjh "<<last<<" "<<v<<endl;
            bp=path;
            last=depth;
        }
    }
    for(int i=0; i<bg[v].size(); ++i)
    {
        if(visited[bg[v][i].a]==0&&bg[v][i].left>0)
        {
            visited[bg[v][i].a]=1;
            depth+=bg[v][i].p;
            bg[v][i].number=i;
            bg[v][i].b=v;
            path.push_back(bg[v][i]);
            dfsbg(bg[v][i].a,t);
            depth-=bg[v][i].p;
            visited[bg[v][i].a]=0;
            path.pop_back();
        }
    }
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
    //    cout<<"hgjjeeeeeeee"<<endl;
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
int main()
{
//    ifstream in("");
//    string filename;
//    getline(cin,filename,'\n');
//    in.open(filename);
//    if(!in){
//
//    }
    int d,s;//network node,network link,comsume node
    int m;//server
    //scanf("%d %d %d %d",&n,&d,&s,&m);
    node c1,c2;
    int flag=1;
    int mean=0;

    string x="",y="",z="",w="";
    ifstream infile;
    char buf[1024]={0};
    infile.open("F:\\case0.txt");
    if(infile.is_open())
    {
        while(infile.good() && !infile.eof())
        {
            //memset(buf,0,1024);
            infile.getline(buf,1024);
            stringstream word(buf);
            word >> x;
            word >> y;
            word >> z;
            n=atoi(x);
            d=atoi(y);
            s=atoi(z);
            infile.getline(buf,1024);

            //memset(buf,0,1024);
            infile.getline(buf,1024);
            stringstream word2(buf);
            word2 >> x;
            m=atoi(x);
            infile.getline(buf,1024);
int o,p,q,r;
            for(int i=0; i<d; ++i)
            {
                //int o,p,q,r;
                //memset(buf,0,1024);
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
                //scanf("%d %d %d %d",&o,&p,&q,&r);
                mean+=r;
               // o=o+n;
                c1.a=o;
                c2.a=p;
                c1.b=p;
                c2.b=o;
                c1.left=c2.left=q;
                c1.p=c2.p=r;
              //  c1.number=g[p].size();
              //  c2.number=g[o].size();
                g[o].push_back(c2);
                g[p].push_back(c1);
            }
            infile.getline(buf,1024);
            for(int i=n; i<n+s; ++i)
            {
               // int o,p,q;
                //memset(buf,0,1024);
                infile.getline(buf,1024);
                stringstream word4(buf);
                word4 >> x;
                word4 >> y;
                word4 >> z;
                o=atoi(x);
                p=atoi(y);
                q=atoi(z);
                o=o+n;
                //scanf("%d %d %d",&o,&p,&q);
           //     cout<<o<<" "<<p<<" "<<q<<endl;
                if(o==p&&q>0)
                {
                    flag=0;//no answer?
                }
                need[o].ne=q;
                need[o].id=o;
                c1.a=o;
                c2.a=p;
                c1.b=p;
                c2.b=o;
                c1.left=c2.left=q;
                c1.p=c2.p=0;
               //  c1.number=g[p].size();
               // c2.number=g[o].size();
                g[o].push_back(c2);
                g[p].push_back(c1);
            }
            infile.getline(buf,1024);
        }
        infile.close();
    }
    for(int i=0;i<1510;++i){
        bg[i]=g[i];
        bgb[i]=g[i];
    }

    if(flag==0)
    {
        printf("NA\n");
        return 0;
    }
    mean/=d;
    mean*=s;
    sort(need+n,need+n+s,cmp);
    double td=0.01,tf=0.0001;
    int md;
    int cost=0,lcost=inf;
    int ans=0;
    int k;
    k=min(0,s/40);
  // cout<<mean<<" "<<k<<endl;
  md=k;
    for(int j=0; j<k; ++j)
    {
        int maxm=0,mark;
        for(int i=0; i<n; ++i)
        {
            if(g[i].size()>maxm&&ht[i]==0)
            {
                maxm=g[i].size();
                mark=i;
            }
        }
        ht[mark]=1;//let mark a server
        cout<<mark<<endl;
    }
    cost=(k)*m;
    int num=0;
    for(int ee=n; ee<n+s; ++ee) //assign path for snode
    {
        int t=m*1.00/need[ee].ne;//threshold
        int i=need[ee].id;
        int ccost=0;
         for(int i=0;i<1510;++i){
       // bg[i]=g[i];
        bgb[i]=g[i];
    }
        while(g[i][0].left>0)
        {
            num++;
            depth=0;
            last=inf;
            init();
            bp.clear();
            path.clear();
            t=(m-ccost)*1.00/g[i][0].left;
           // cout<<i<<" "<<g[i][0].left<<" "<<t<<endl;
            dfs(i,t);
            int mini=g[i][0].left;
            int up=0;
            if(bp.size()==0){
                for(int j=gp[i].size()-1; j>=0; --j)
        {
                  int v=gp[i][j].b;
                int u=gp[i][j].number;
                if(v!=i)
                g[v][u].left=bgb[v][u].left;
        }
        gp[i].clear();
        g[i][0]=bg[i][0];//restore
          gp[i].push_back(g[i][0]);
            g[i][0].left=0;
            cost+=m;
            cost-=ccost;
            ccost=0;
            ht[g[i][0].a]=1;
            md++;
         }
         else{
            for(int j=0; j<bp.size(); ++j)
            {
             //   cout<<bp[j].b<<" ";
                if(bp[j].left<mini)
                {
                    mini=bp[j].left;
                }
                up+=bp[j].p;
            }
          //  cout<<i<<endl;
          node current;
          current.a=g[i][0].a;
          current.b=g[i][0].b;
          current.left=mini;
          //  gp[i].push_back(mini);
            gp[i].push_back(current);
            //  cout<<i<<" ";
            for(int j=0; j<bp.size(); ++j)
            {
              // cout<<bp[j].b<<" ";
                int v=bp[j].b;
                int u=bp[j].number;
                if(v!=i)
                g[v][u].left-=mini;
             //   cout<<v<<" bnmhhj ";
               // bp[j].left-=mini;
            //   cout<<v<<" v u "<<u<<endl;
            if(v!=i)
                gp[i].push_back(bp[j]);
               // cout<<bp[j].a<<" ";
            }
         //   cout<<mini<<" "<<g[i][0].left<<endl;
    //    cout<<current.left<<endl;
            cost+=mini*up;
            ccost+=mini*up;
            g[i][0].left-=mini;
         }
//<<g[i][0].left<<" "<<endl;
        }
       // cout<<ccost<<" "<<i-n<<endl;
      //  cout<<g[i][0].left<<" "<<i<<endl;
    }
    cout<<cost<<" "<<num<<endl;
     for(int i=n; i<n+s; ++i)
    {
      //  cout<<i<<endl;
        for(int j=gp[i].size()-1; j>=0; --j)
        {
            if(gp[i][j].b==i)
            {
                printf("%d %d %d\n",gp[i][j].a,gp[i][j].b-n,gp[i][j].left);
                 if(ht[gp[i][j].a]==0)
                ct[gp[i][j].a]++;
            }
            else
            {
                printf("%d ",gp[i][j].a);
                if(ht[gp[i][j].a]==0)
                ct[gp[i][j].a]++;
            }
        }
    }
    /*int c=max(0,s/100);
    for(int j=0; j<c; ++j)
    {
        int maxm=0,mark;
        for(int i=0; i<n; ++i)
        {
            if(ct[i]>maxm&&ht[i]==0)
            {
                maxm=ct[i];
                mark=i;
            }
        }
        ht[mark]=1;//let mark a server
        cout<<mark<<endl;
        md++;
    }*/
    int num1=0;
    int cost1=md*m;
     for(int ee=n; ee<n+s; ++ee) //assign path for snode
    {
        int t=m*1.00/need[ee].ne;//threshold
        int i=need[ee].id;
        int ccost=0;
        while(bg[i][0].left>0)
        {
            num1++;
            depth=0;
            last=inf;
            init();
            bp.clear();
            path.clear();
            t=(m-ccost)*1.00/bg[i][0].left;
           // cout<<i<<" "<<g[i][0].left<<" "<<t<<endl;
            dfsbg(i,t);
            int mini=bg[i][0].left;
            int up=0;
            for(int j=0; j<bp.size(); ++j)
            {
             //   cout<<bp[j].b<<" ";
                if(bp[j].left<mini)
                {
                    mini=bp[j].left;
                }
                up+=bp[j].p;
            }
          //  cout<<i<<endl;
          node current;
          current.a=bg[i][0].a;
          current.b=bg[i][0].b;
          current.left=mini;
          //  gp[i].push_back(mini);
            bgp[i].push_back(current);
            //  cout<<i<<" ";
            for(int j=0; j<bp.size(); ++j)
            {
              // cout<<bp[j].b<<" ";
                int v=bp[j].b;
                int u=bp[j].number;
                if(v!=i)
                bg[v][u].left-=mini;
             //   cout<<v<<" bnmhhj ";
               // bp[j].left-=mini;
            //   cout<<v<<" v u "<<u<<endl;
            if(v!=i)
                bgp[i].push_back(bp[j]);
               // cout<<bp[j].a<<" ";
            }
         //   cout<<mini<<" "<<g[i][0].left<<endl;
    //    cout<<current.left<<endl;
            cost1+=mini*up;
            ccost+=mini*up;
            bg[i][0].left-=mini;
         }
       //  cout<<ccost<<" "<<i-n<<endl;
//<<g[i][0].left<<" "<<endl;
        }
      //  cout<<g[i][0].left<<" "<<i<<endl
        printf("%d %d\n",cost1,num1);
    for(int i=n; i<n+s; ++i)
    {
      //  cout<<i<<endl;
        for(int j=bgp[i].size()-1; j>=0; --j)
        {
            if(bgp[i][j].b==i)
            {
                printf("%d %d %d\n",bgp[i][j].a,bgp[i][j].b-n,bgp[i][j].left);
            }
            else
            {
                printf("%d ",bgp[i][j].a);
            }
        }
    }
    int countm=0;
    for(int i=0;i<1010;++i){
        if(ht[i]==1){
                cout<<i<<endl;
            countm++;
        }
    }
    cout<<cost<<" "<<num<<endl;
    cout<<cost1<<" "<<num1<<endl;
    cout<<k<<" "<<md<<endl;
    return 0;
}

