#include<bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,ll>mp;

ll power(ll a,ll b , ll m)
{
    ll res = 1;

    while(b>0)
    {
        if(b&1)
        {
            res = (res%m * a%m)%m;
        }
        b>>=1;
        a = (a%m * a%m)%m;
    }

    return res%m;

}


ll inverse(ll a, ll m)
{
    for(ll i=1;i<m;i++)
    {
        if((i*a)%m == 1)
        {
            return i;
        }
    }

    return -1;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll calculate_primitive_root(ll p)
{
    ll root;

    for(ll i = 2;i<p;i++)
    {
        map<ll, ll>mp;
        bool flag = true;
        for (ll j=1;j<p;j++)
        {
            ll x = power(i,j,p);


            if(mp[x]!=0)
            {
                flag = false;
                break;
            }
            else
            {
                mp[x]++;
            }

        }

        if (flag)
        {
            root = i;
            break;
        }

    }

    return root;

}

ll randomInteger(ll k)
{
    ll x = -1;
    for(ll i=2;i<k;i++)
    {
        if(gcd(i,k-1)==1)
        {
            x = i;
            break;
        }
    }
    return x;


}

int main()
{
    ll private_key,prime,primitive_root,k,public_key;

    prime = 7;

    private_key = rand()%(prime-2) + 1;

    primitive_root = calculate_primitive_root(prime);

    k = randomInteger(prime);
    cout<<private_key<<" "<<primitive_root<<" "<<k<<endl;

    public_key = power(primitive_root,private_key,prime);
    cout<<public_key<<endl;

    ll m;
    cin>>m;

    ll c1 = power(primitive_root,k,prime);

    cout<<c1<<endl;
    ll c2 = ((m - (private_key * c1))  * inverse(k,prime-1) )%(prime-1);
    if (c2<0)
    {
        c2 += (prime-1);
    }
    cout<<c2<<endl;
    ll v1 = (power(c1,c2,prime) * power(public_key,c1,prime))%(prime);
    ll v2 = power(primitive_root,m,prime);

    cout<<v1<<" "<<v2<<endl;



    return 0;
}
