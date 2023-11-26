//Hoang Quoc Viet-20210936
#include<bits/stdc++.h>
using namespace std;
string uid,Pid,tim,sta;
int Point;
struct pb{
    int a[25]={};
};
map< string , int > map_ERR;
map< string , pb > map_pt;
int ERR[1000005]={};
int Poi[1000005][20]={};
int res1=0,res2=0;
int sub[100005]={};
int convert(string t){
    return ((t[0]-'0')*10+t[1]-'0')*3600+ ((t[3]-'0')*10+t[4]-'0')*60+ ((t[6]-'0')*10+t[7]-'0');
}
int change(string uid){
    int n=uid.length();
    int id=0;
    for(int i=1;i<n;i++){
        id=id*10+uid[i]-'0';
    }
    return id;
}
int main(){
  //  #define NAME "W8-2."
  //  freopen(NAME"inp","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>uid){
        if(uid=="#"){
            break;
        }
        cin>>Pid>>tim>>sta>>Point;
        int tmp=(sta=="ERR");
        res1++;
        res2+=tmp;
        if(uid.length()>6){
        map_ERR[uid]+=tmp;
        map_pt[uid].a[(Pid[1]-'0')*10+Pid[2]-'0']=max(Point,map_pt[uid].a[(Pid[1]-'0')*10+Pid[2]-'0']);
        }
        else{
            int id=change(uid);
            ERR[id]+=tmp;
            Poi[id][(Pid[1]-'0')*10+Pid[2]-'0']=max(Point, Poi[id][(Pid[1]-'0')*10+Pid[2]-'0']);
        }
        sub[convert(tim)]++;
    }
    for(int i=1;i<=100000;i++) sub[i]+=sub[i-1];
    string req;
    while(cin>>req){
        if(req=="#"){
            break;
        }
        if(req=="?total_number_submissions"){
            cout<<res1<<'\n';
        }
        if(req=="?number_error_submision"){
            cout<<res2<<'\n';
        }
        if(req=="?number_error_submision_of_user"){
            cin>>uid;
            if(uid.length()>6){
            cout<<map_ERR[uid]<<'\n';
            }
            else{
                cout<<ERR[change(uid)]<<'\n';
            }
        }
        if(req=="?total_point_of_user"){
            cin>>uid;
            int res=0;
            if(uid.length()>6){
            for(int i=0;i<=19;i++){
                res+=map_pt[uid].a[i];
            }
            }
            else{
                int id=change(uid);
                for(int i=0;i<=19;i++)
                    res+=Poi[id][i];
            }
            cout<<res<<'\n';
        }
        if(req=="?number_submission_period"){
            string t1,t2;
            cin>>t1>>t2;
            cout<<sub[convert(t2)]-sub[convert(t1)-1]<<'\n';
        }
    }
    return 0;

}