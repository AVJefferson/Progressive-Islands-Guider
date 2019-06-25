/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
const char en='\n';
typedef long long int ll;

struct Guider {

	int m[1001],HAR,l,a,n;
	int pr1[1001][1001];
	int h[1001][1001],mi[1001][1001],s[1001][1001]; //not memset
	int ti[51][30001];
	int pr2[1001][1001]; //not memset
	int dp[51][30001];
	vector<int> ho[51][30001];
	bool bio[51][30001];
	int mat[1001];
	int wh[1001];
	int re[1001];
	int mgc=0;
	string names[51],name[51];
	const int MAXGEMS=200000;
	
	int dp1(int i,int j)
	{
		if (j<0) return MAXGEMS;
		if (i<0) return 0;
		if (bio[i][j]) return dp[i][j];
		bio[i][j]=1;
		int mi=-1;
		for (int k=0;k<m[i];++k)
		{
			if (i==0 && pr1[i][k]<HAR*60) continue;
			if (mi==-1 || pr2[i][k]+dp1(i-1,j-pr1[i][k])<pr2[i][mi]+dp1(i-1,j-pr1[i][mi]) ||
				((pr2[i][k]+dp1(i-1,j-pr1[i][k])==pr2[i][mi]+dp1(i-1,j-pr1[i][mi])) && (ti[i-1][j-pr1[i][k]]<ti[i-1][j-pr1[i][mi]]))) mi=k;
		}
		if (j-pr1[i][mi]<0) return dp[i][j]=MAXGEMS;
		if (mi==-1) return dp[i][j]=MAXGEMS;
		if (i==0)
		{
			vector<int> o;
			o.push_back(mi);
			ho[i][j]=o;
			ti[i][j]=pr1[i][mi];
		}
		else
		{
			vector<int> o=ho[i-1][j-pr1[i][mi]];
			o.push_back(mi);
			ho[i][j]=o;
			ti[i][j]=pr1[i][mi]+ti[i-1][j-pr1[i][mi]];
		}
		return dp[i][j]=pr2[i][mi]+dp1(i-1,j-pr1[i][mi]);
	}
	
	void init()
	{
		memset(mat,0,sizeof(mat));
		memset(wh,0,sizeof(wh));
		memset(re,0,sizeof(re));
		memset(bio,0,sizeof(bio));
		memset(dp,0,sizeof(dp));
		memset(ti,0,sizeof(ti));
		memset(pr1,0,sizeof(pr1));
	}
	
	void doEverything()
	{
		ofstream fout("ProgressiveGuider.txt");
		for (int i=1;i<=n;++i)
		{
			if (names[i].substr(0,6)=="ignore") name[i]=names[i].substr(6);
			else name[i]=names[i];
		}
		l*=1440;
		l+=a*60;
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<m[i];++j)
			{
				mi[i][j]+=s[i][j]/60;
				s[i][j]%=60;
				h[i][j]+=mi[i][j]/60;
				mi[i][j]%=60;
				pr1[i][j]=h[i][j]*1440+mi[i][j]*60+s[i][j];
			}
		}
		for (int i=n-1;i>=0;--i)
		{
			mat[i]=mat[i+1]+pr1[i][m[i]-1];
		}
		l+=2880;
		int zzqw=l;
		while (n)
		{
			l=zzqw;
			if (names[n].substr(0,6)=="ignore")
			{
				--n;
				continue;
			}
			fout<<"Quest "<<names[n]<<':'<<endl;
			for (int o=0;o<20 && l>=HAR;++o)
			{
				for (int i=0;i<n;++i)
				{
					for (int j=0;j<l;++j)
					{
						bio[i][j]=0;
						dp[i][j]=0;
						ho[i][j].clear();
					}
				}
				mgc=dp1(n-1,l);
				l-=480;
				if (mgc==0) continue;
				l+=480;
				bool ima=0;
				for (int i=0;i<n;++i)
				{
					//cout<<ho[n-1][l].size()<<en;
					re[i]=ho[n-1][l][i];
					if (mi[i][re[i]]%8)
					{
						fout<<"On "<<name[i+1]<<", use "<<pr2[i][re[i]]<<" gems at "<<h[i][re[i]]<<" days and "<<mi[i][re[i]]<<" hours."<<endl;
						ima=1;
					}
					else
					{
						fout<<"On "<<name[i+1]<<", use "<<pr2[i][re[i]]<<" gems after "<<(mi[i][re[i]]/8+h[i][re[i]]*3)<<" collection";
						if ((mi[i][re[i]]/8+h[i][re[i]]*3)!=1) fout<<'s';
						fout<<", not including the first one."<<endl;
					}
				}
				fout<<"Total gem cost: "<<mgc<<" gems."<<endl;
				if (ima) fout<<"Total time: "<<ti[n-1][l]/1440<<" days and "<<(ti[n-1][l]%1440)/60<<" hours.";
				else fout<<"Total collections(not including the first one on each node): "<<ti[n-1][l]/480<<".";
				fout<<endl<<endl<<endl;
				l-=480;
			}
			for (int i=0;i<15;++i) fout<<'\n';
			n--;
		}
	}

};

/*struct Guider
{
	int HAR;
	void init() {
	};
	int l,a,n;
	int**pr2;
	int**h;
	int**mi;
	int**s;
	int*m;
	string*names;
};*/

int t;
int gi,fi,bi,hi,fight,ge,meg,mef,mei,meb,meh,pvp,mep;
int disc;
double gt,ft;
int cosgf[1010][1010];
int costf[1010][1010];
int bre[1010][1010];
int pvpp[1010][1010];
int fig[][4]={{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,3,10,21},
	{0,0,0,0},
	{0,5,16,33},
	{0,0,0,0},
	{0,0,0,0},
	{0,3,8,15},
	{0,0,0,0},
	{0,10,30,60},
	{0,0,0,0},
	{0,3,7,12},
	{0,3,12,27}};
const int MAXDIS=2000;
const int MAMIN1=MAXDIS-1;

int cost1(int go,int fo,int fi,int bi,int hi,int pv,int mg,int mf,int mi,int mb,int mh,int mp)
{
	int el=(go<0?0:cosgf[go][mg])+(fo<0?0:costf[mf][fo])+(fi<0?0:fig[mi][fi])+((bi<0)?0:bre[bi][mb])+((hi<0)?0:bre[hi][mh])+((pv<0)?0:pvpp[mp][pv]);
	return el;
}

int cost(int go,int fo,int fi,int bi,int hi,int pv,int mg,int mf,int mi,int mb,int mh,int mp)
{
	return min((((go<0?0:cosgf[go][mg])+(fo<0?0:costf[mf][fo])+(fi<0?0:fig[mi][fi])+((bi<0)?0:bre[bi][mb])+((hi<0)?0:bre[hi][mh])+((pv<0)?0:pvpp[mp][pv]))*disc+MAMIN1)/MAXDIS,
	(((go<0?0:cosgf[go][mg])+(fo<0?0:costf[mf][fo])+((bi<0)?0:bre[bi][mb])+((hi<0)?0:bre[hi][mh])+((pv<0)?0:pvpp[mp][pv]))*disc+MAMIN1)/MAXDIS+max(fi,0)*2);
}

int max(double a,int b)
{
	if (a<b) return int(a);
	return b;
}

int pool=8;
int HOUR;

int main()
{
	freopen("log.txt","w",stdout);
	cout<<"Program started."<<endl<<flush;
	ifstream fin("progressiveInput.txt");
	fin>>HOUR;
	cout<<"Every "<<HOUR<<" hours."<<endl;
	cosgf[1][1]=1;
	cosgf[0][1]=0;
	cosgf[1][2]=2;
	cosgf[0][2]=0;
	cosgf[1][3]=3;
	cosgf[0][3]=0;
	for (int i=1;i<1000;++i) pvpp[1][i]=i*(i+1)/2;
	for (int i=2;i<1000;i+=2)
	{
		for (int j=1;j<=3;++j)
		{
			cosgf[i][j]=cosgf[i-1][j]+cosgf[i-1][j]-cosgf[i-2][j]+1;
			cosgf[i+1][j]=cosgf[i][j]+(cosgf[i][j]-cosgf[i-1][j])+2;
			//if (i<40)cout<<j<<' '<<i<<' '<<cosgf[i][j]<<endl<<i+1<<' '<<cosgf[i+1][j]<<endl;
		}
	}
	costf[5][1]=5;
	cosgf[1][5]=5;
	bre[1][10]=10;
	costf[12][1]=1;
	for (int i=2;i<1000;++i)
	{
		costf[5][i]=cosgf[i][5]=costf[5][i-1]*2-costf[5][i-2]+3;
		bre[i][10]=bre[i-1][10]*2-bre[i-2][10]+3;
	}
	for (int i=2;i<1000;i+=2)
	{
		costf[12][i]=costf[12][i-1]*2-costf[12][i-2];
		costf[12][i+1]=costf[12][i]*2-costf[12][i-1]+1;
	}
	costf[3][1]=3;
	for (int i=2;i<1000;++i) costf[3][i]=costf[3][i-1]+i+2;
	for (int i=1;i<1000;++i) costf[1][i]=costf[1][i-1]+i;
	costf[2][1]=2;
	for (int i=2;i<1000;++i) costf[2][i]=costf[2][i-1]+i+1;
	for (int i=1;i<1000;++i) costf[21][i]=cosgf[i][21]=costf[1][i]*2;
	for (int i=1;i<1000;++i) bre[i][31]=bre[i-1][31]+2*i+1/*,cout<<bre[i][31]<<' '*/;
	//cout<<cosgf[55][21]<<' '<<costf[21][30]<<' '<<fig[3][3]<<' '<<bre[8][31]<<endl;
	//cout<<endl;
	for (int i=1;i<1000;++i) costf[11][i]=cosgf[i][1];
	for (int i=1;i<1000;++i) bre[i][51]=bre[i][31]+2*i;
	costf[14][1]=1;
	for (int i=2;i<1000;++i) costf[14][i]=costf[14][i-1]*2-costf[14][i-2]+3;
	bre[1][3]=3;
	bre[1][4]=4;
	bre[1][41]=4;
	bre[1][42]=4;
	bre[1][33]=3;
	bre[1][34]=3;
	for (int i=2;i<1000;++i) bre[i][42]=bre[i-1][42]*2-bre[i-2][42]+2;
	for (int i=2;i<1000;i+=2)
	{
		for (int j=3;j<=4;++j)
		{
			bre[i][j]=bre[i-1][j]+bre[i-1][j]-bre[i-2][j]+1;
			bre[i+1][j]=bre[i][j]+(bre[i][j]-bre[i-1][j])+2;
		}
		bre[i][41]=bre[i-1][41]+bre[i-1][41]-bre[i-2][41]+2;
		bre[i+1][41]=bre[i][41]+bre[i][41]-bre[i-1][41]+3;
		bre[i][33]=bre[i-1][33]+bre[i-1][33]-bre[i-2][33]+2;
		bre[i+1][33]=bre[i][33]+bre[i][33]-bre[i-1][33]+3;
		bre[i][34]=bre[i-1][34]*2-bre[i-2][34]+1;
		bre[i+1][34]=bre[i][34]*2-bre[i-1][34]+1;
	}
	cosgf[1][31]=3;
	for (int i=2;i<1000;++i) cosgf[i][31]=cosgf[i-1][31]*2-cosgf[i-2][31]+1;
	bre[1][43]=4;
	bre[2][43]=11;
	for (int i=2;i<1000;++i) bre[i][43]=bre[i-1][43]*2-bre[i-2][43]+3;
	for (int i=1;i<1000;++i) cosgf[i][11]=costf[1][i];
	bre[1][32]=3;
	for (int i=2;i<1000;++i) bre[i][32]=bre[i-1][32]*2-bre[i-2][32]+5;
	fin>>t;
	/*for (int j=1;j<=59;++j)
	{
		cout<<j<<' ';
		for (int i=1;i<10;++i) cout<<cosgf[i][j]-cosgf[i-1][j]<<" \n"[i==9];
	}
	cout<<endl;
	for (int j=1;j<=59;++j)
	{
		cout<<j<<' ';
		for (int i=1;i<10;++i) cout<<costf[j][i]-costf[j][i-1]<<" \n"[i==9];
	}
	cout<<endl;
	for (int j=1;j<=59;++j)
	{
		cout<<j<<' ';
		for (int i=1;i<10;++i) cout<<bre[i][j]-bre[i-1][j]<<" \n"[i==9];
	}*/
	//cout<<en;
	//for (int i=0;i<100;++i) cout<<cosgf[i][1]<<' ';
	//cout<<endl<<cosgf[21][1]<<' '<<cosgf[20][1];
	/*GOLD:
	1-1,2,4,5,7,8,10,...
	2-2,3,5,6,8,9,11,...
	3-3,4,6,7,9,10,12,...
	5-5,8,11,14,17,20,23,...
	11-1,2,3,4,5,6,7,...
	21-2,4,6,8,10,12,14,...
	31-3,4,5,6,7,8,9,...
	*/
	
	/*FOOD:
	1-1,2,3,4,5,6,...
	2-2,3,4,5,6,7,...
	3-3,4,5,6,7,8,...
	5-5,8,11,14,17,20,...
	11-1,2,4,5,7,8,...
	21-2,4,6,8,10,12,...
	12-1,1,2,2,3,3,4,4,...
	14-1,4,7,10,13,16,...
	*/
	
	/*BREEDING:
	3-3,4,6,7,9,10,12,...
	4-4,5,7,8,10,11,13,...
	10-10,13,16,19,22,25,...
	31-3,5,7,9,11,13,15,...
	32-3,8,13,18,23,28,33,38,...
	33-3,5,8,10,13,15,18,...
	34-3,4,5,6,7,8,9,10,...
	41-4,6,9,11,14,16,19,...
	42-4,6,8,10,12,14,16,...
	43-4,7,10,13,16,19,22,...
	51-5,7,9,11,13,15,17,...
	*/
	
	/*PVP:
	1-1,2,3,4,5,...
	*/
	cout<<fixed<<setprecision(6);
	cout<<"Initialization finished."<<endl;
	int ko=0;
	const bool doSolution=1;
	Guider solution;
	if (doSolution) solution.init();
	for (int i=0;i<t;++i)
	{
		bool x;
		fin>>gi>>fi>>fight>>bi>>hi>>pvp>>ge>>meg>>mef>>mei>>meb>>meh>>mep>>x;
		cout<<endl<<endl<<endl<<"NEW NODE STARTS NOW"<<endl;
		//cout<<cosgf[gi][meg]<<endl;
		//cout<<(gi<0?0:cosgf[gi][meg])<<' '<<(fi<0?0:costf[mef][fi])<<' '<<(fight<0?0:fig[mei][fight])<<' '<<((bi<0)?0:bre[bi][meb])<<' '<<((hi<0)?0:bre[hi][meh])<<endl;
		//cout<<gi<<' '<<fi<<' '<<fight<<' '<<bi<<' '<<hi<<' '<<ge<<' '<<meg<<' '<<mef<<' '<<mei<<' '<<meb<<' '<<meh<<endl;
		cout<<cost1(gi,fi,fight,bi,hi,pvp,meg,mef,mei,meb,meh,mep)<<' '<<ge<<endl<<"Possible discounts: ";
		if (cost1(gi,fi,fight,bi,hi,pvp,meg,mef,mei,meb,meh,mep)==ge) disc=1;
		bool go=0;
		for (int i=1;i<=100;++i) if ((cost1(gi,fi,fight,bi,hi,pvp,meg,mef,mei,meb,meh,mep)*i+99)/100==ge) cout<<i<<"% ",disc=i*MAXDIS/100,go=1;
		if (!go) for (int i=1;i<=200;++i) if ((cost1(gi,fi,fight,bi,hi,pvp,meg,mef,mei,meb,meh,mep)*i+199)/200==ge) cout<<i/2<<".5"<<"% ",disc=i*MAXDIS/200,go=1;
		if (!go) for (int i=1;i<=1000;++i) if ((cost1(gi,fi,fight,bi,hi,pvp,meg,mef,mei,meb,meh,mep)*i+999)/1000==ge) cout<<i/10<<"."<<i%10<<"% ",disc=i*MAXDIS/1000,go=1;
		if (!go) for (int i=1;i<=2000;++i) if ((cost1(gi,fi,fight,bi,hi,pvp,meg,mef,mei,meb,meh,mep)*i+1999)/2000==ge) cout<<i/20<<"."<<(i%20>1?"":"0")<<(i%20)*5<<"% ",disc=i*MAXDIS/2000,go=1;
		cout<<disc<<"/"<<MAXDIS<<endl;
		int gp=6,fp=4;
		int gt=(gi-gp*!x)*(pool*60/gp),ft=(fi-fp*!x)*(pool*60/fp);
		//cout<<gi<<' '<<fi<<' '<<gt<<' '<<ft<<' '<<cost(gi-1,fi,fight,bi,hi,pvp,meg,mef,mei,meb,meh,mep)<<endl;
		int prg=cost(gi,fi,fight,bi,hi,pvp,meg,mef,mei,meb,meh,mep);
		//cout<<prg<<en;
		int mat=max(max(gt,ft),60*max(max((fight-!ko*!x)*2,(hi-1*!x)*pool),(bi-1*!x)*pool));
		//cout<<mat<<endl;
		int pgi=gi,pfi=fi,pfight=fight,phi=hi,pbi=bi,ppv=pvp;
		//cout<<mat<<en;
		//fout<<(mat+(HOUR*60-1))/(HOUR*60)+1<<en;
		if (doSolution) solution.m[i]=(mat+(HOUR*60-1))/(HOUR*60)+1;
		if (x==0)
		{
			pgi-=gp;
			pfi-=fp;
			--pfight;
			--phi;
			--pbi;
			ppv-=3;
		}
		//fout<<"0 0 "<<0<<" "<<cost(pgi,pfi,pfight,pbi,phi,ppv,meg,mef,mei,meb,meh,mep)<<en;
		if (doSolution) solution.pr2[i][0]=cost(pgi,pfi,pfight,pbi,phi,ppv,meg,mef,mei,meb,meh,mep);
		int coun=0;
		int i1=i;
		for (int i=HOUR;i*60-HOUR*60<mat;i+=HOUR)
		{
			++coun;
			/*--pgi;
			fout<<min(i*60+80,mat)/1440<<' '<<(min(i*60+80,mat)/60)%24<<' '<<min(i*60+80,mat)%60<<" "<<cost(pgi,pfi,pfight,pbi,phi,pvp,meg,mef,mei,meb,meh,mep)<<en;
			--pfi;
			--pfight;
			fout<<min(i*60+120,mat)/1440<<' '<<(min(i*60+120,mat)/60)%24<<' '<<min(i*60+120,mat)%60<<" "<<cost(pgi,pfi,pfight,pbi,phi,pvp,meg,mef,mei,meb,meh,mep)<<en;
			--pgi;
			fout<<min(i*60+160,mat)/1440<<' '<<(min(i*60+160,mat)/60)%24<<' '<<min(i*60+160,mat)%60<<" "<<cost(pgi,pfi,pfight,pbi,phi,pvp,meg,mef,mei,meb,meh,mep)<<en;
			--pgi;
			--pfi;
			--pfight;
			if (i%8==0)
			{
				--phi;
				--pbi;
			}
			fout<<min(i*60+240,mat)/1440<<' '<<(min(i*60+240,mat)/60)%24<<' '<<min(i*60+240,mat)%60<<" "<<cost(pgi,pfi,pfight,pbi,phi,pvp,meg,mef,mei,meb,meh,mep)<<en;
			//cout<<i<<' '<<pool<<' '<<pgi<<' '<<pfi<<' '<<pfight<<' '<<pbi<<' '<<phi<<en;*/
			pgi=gi-gp*!x-i*gp/pool;
			pfi=fi-fp*!x-i*fp/pool;
			pfight=fight-1-i/2;
			pbi=bi-!x-i/pool;
			phi=hi-!x-i/pool;
			ppv=pvp-3*!x-i*4/pool;
			//fout<<i/24<<' '<<i%24<<' '<<0<<' '<<cost(pgi,pfi,pfight,pbi,phi,ppv,meg,mef,mei,meb,meh,mep)<<endl;
			cout<<i1<<' '<<coun<<endl;
			if (doSolution) solution.h[i1][coun]=i/24;
			if (doSolution) solution.mi[i1][coun]=i%24;
			if (doSolution) solution.pr2[i1][coun]=cost(pgi,pfi,pfight,pbi,phi,ppv,meg,mef,mei,meb,meh,mep);
		}
		/*if (fight)
		{
			gi-=gp;
			fi-=fp;
			if (ko==0) --fight;
			--hi;
			--bi;
			--gi;
			--fi;
			--fight;
			fout<<"0 0 120 "<<cost(gi,fi,fight,bi,hi,meg,mef,mei,meb,meh)<<en;
			if (ko!=0)
			{
				--fight;
				--fight;
				--gi;
				--gi;
				--gi;
				--fi;
				--fi;
				fout<<"0 0 360 "<<cost(gi,fi,fight,bi,hi,meg,mef,mei,meb,meh)<<en;
			}
		}*/
		++ko;
	}
	//cout<<cost1(57,31,1,8,8,11,12,12,34,34)<<' '<<cost1(57,31,0,8,8,11,12,12,34,34)<<endl;
	if (doSolution) solution.n=t;
	int l,a,HAR;
	fin>>HAR>>l>>a;
	if (doSolution) solution.HAR=HAR;
	if (doSolution) solution.l=l;
	if (doSolution) solution.a=a;
	string aaa;
	getline(fin,aaa);
	if (doSolution) for (int i=1;i<=t;++i) getline(fin,solution.names[i]);
	solution.doEverything();
}

