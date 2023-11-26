#include<bits/stdc++.h>

using namespace std;

int bornd[3000005]={};
int res1=0;
int res2=0;
map<string ,string > far, mot;
map<string , vector< string > > adj;
map<string , int > dd;
string code,bir,fcode,mcode,ali,recode;

int converter(string t) {
    int year = (t[0] - '0')*1000 +(t[1]-'0')*100 +(t[2]-'0')*10 + (t[3]-'0')-1900;
    int month = (t[5]-'0')*10 + t[6]-'0';
    int day = (t[8]-'0')*10 + t[9]-'0';
    return year * 1000 + month * 50 + day;
}

int dem1 ,dem2;
void dfs(string u, int i){
    dd[u]=i;
    if(i==1)dem1++;
    else dem2++;
    for(auto v: adj[u]){
        if(dd[v]==0){

            dfs(v,3-i);
        }
    }
}
int ancestor(string con){
    int fa,ma;
    if(far[con]=="0000000") fa=0;
    else fa= ancestor(far[con]);
    if(mot[con]=="0000000") ma=0;
    else ma= ancestor(mot[con]);
    return max(fa,ma)+1;
}
int main(){
  //  #define NAME "W8-1."
 //   freopen(NAME"inp","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>code){
        if(code=="*"){
            break;
        }
        cin>>bir>>fcode>>mcode>>ali>>recode;
        res1++;
        bornd[convert(bir)]++;
        far[code]=fcode;
        mot[code]=mcode;
        dd[code]=0;
       if(fcode!="0000000") {
            adj[code].push_back(fcode);
            adj[fcode].push_back(code);
       }
       if(mcode!="0000000") {
            adj[code].push_back(mcode);
            adj[mcode].push_back(code);
       }
    }

    for(auto v: dd){
        if(dd[v.first]==0){
            dem1=0;
            dem2=0;
            dfs(v.first,1);
            res2+=max(dem1,dem2);
        }
    }


    for(int i=1;i<=3000000;i++)bornd[i]+=bornd[i-1];
    string req;
    while(cin>>req){
        if(req=="*"){
            break;
        }
        if(req=="NUMBER_PEOPLE"){
            cout<<res1<<'\n';
        }
        if(req=="NUMBER_PEOPLE_BORN_AT"){
            string day;cin>>day;
            int tmpday=converter(day);
            cout<<bornd[tmpday]-bornd[tmpday-1]<<'\n';
        }
        if(req=="MOST_ALIVE_ANCESTOR"){
            cin>>code;
            cout<<ancestor(code)-1<<'\n';
        }
        if(req=="NUMBER_PEOPLE_BORN_BETWEEN"){
            string fdate,tdate;
            cin>>fdate>>tdate;
            cout<<bornd[converter(tdate)] - bornd[convert(fdate) - 1]<<'\n';
        }
        if(req=="MAX_UNRELATED_PEOPLE"){
            cout<<res2<<'\n';
        }
    }
    return 0;
}