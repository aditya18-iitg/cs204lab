#include <bits/stdc++.h>
using namespace std;


bool isSmaller(string str1, string str2) 
{ 
	int n1 = str1.length(), n2 = str2.length(); 

	if (n1 < n2) 
	return true; 
	if (n2 < n1) 
	return false; 

	for (int i=0; i<n1; i++) 
	if (str1[i] < str2[i]) 
		return true; 
	else if (str1[i] > str2[i]) 
		return false; 

	return false; 
} 
bool esmall(string str1, string str2) 
{ 
	int n1 = str1.length(), n2 = str2.length(); 

	if (n1 < n2) 
	return true; 
	if (n2 < n1) 
	return false; 

	for (int i=0; i<n1; i++) 
	if (str1[i] < str2[i]) 
		return true; 
	else if (str1[i] > str2[i]) 
		return false; 

	return true; 
} 
string Diff(string str1, string str2) 
{ 
	if (isSmaller(str1, str2)) 
		swap(str1, str2); 
	string str = ""; 
	int n1 = str1.length(), n2 = str2.length(); 

	reverse(str1.begin(), str1.end()); 
	reverse(str2.begin(), str2.end()); 
	
	int carry = 0; 
 
	for (int i=0; i<n2; i++) 
	{ 
		
		int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
		
		if (sub < 0) 
		{ 
			sub = sub + 10; 
			carry = 1; 
		} 
		else
			carry = 0; 

		str.push_back(sub + '0'); 
	} 
 
	for (int i=n2; i<n1; i++) 
	{ 
		int sub = ((str1[i]-'0') - carry); 
		
		if (sub < 0) 
		{ 
			sub = sub + 10; 
			carry = 1; 
		} 
		else
			carry = 0; 
			
		str.push_back(sub + '0'); 
	} 
 
	reverse(str.begin(), str.end()); 

	return str; 
} 
string division(string &a , string &b){
	string ans="";
	string zero="0";
	if(isSmaller(a,b)) {return zero;}
	string r=a.substr(0,b.size());
	if(isSmaller(r,b)) {r+=a[b.size()];}
	int sz=r.size();
	while(esmall(b,r)){
		int i=0;
		while(esmall(b,r)){
			r=Diff(b,r);
			int count=0;
			for(int j=0;j<r.size();j++){
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.size()) {r=r.substr(count,r.size()-count);}
			else{ r="";}
			i++;
		}
		ans+=(i+'0');
		if(sz>=a.size()) break;
		r+=a[sz];
		sz++;
		int count=0;
    	for(int j=0;j<r.size();j++){
			if(r[j]!='0') break;
			else count++;
		}
		if(count<r.size()) r=r.substr(count,r.size()-count);
		else r="";
		while(isSmaller(r,b)&&sz<a.size()){
			r+=a[sz];
			sz++;
			ans+='0';
			int count=0;
			for(int j=0;j<r.size();j++){
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.size()) r=r.substr(count,r.size()-count);
			else r="";
		}
	}
	if(r.size()==0) r="0";
	return r;
}
int main(){

	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		cout<<division(a,b)<<endl<<b<<endl;
	}
	return 0;
}
