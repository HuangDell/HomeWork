# 1.
string changeString(string input)
{
    int size=input.size();
    string odd,even,ans;
    for(int i=0;i<size;i++)
    {
        if ((i+1) % 2 == 0)
            even.push_back(input[i]);
        else 
            odd.push_back(input[i]);
    }
    std::reverse(even.begin(),even.end());
    ans.append(odd).append(even);
    return ans;
}

int main(void)
{
    string input;
    cin>>input;
    string changed=changeString(input);
    cout<<changed;
}


# 2.
char findChar(node*s,node*t)
{
    int dp[256]={0};
    while(t)
    {
        dp[t->ch]=1;
        t=t->next;
    }
    while(s)
    {
        if(dp[s->ch]==0)
            return s->ch;
        s=s->next;
    }
    return 0;
}

# 3.
int main(void)
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    vector<pair<int,int>> row_min;
    vector<pair<int,int>> ans;
    for(int i=0;i<m;i++)
    {
        int min=INT_MAX,index=0;
        for(int j=0;j<n;j++)
            if(matrix[i][j]<min)
            {
                min=matrix[i][j];
                index=j;
            }
        row_min.push_back(make_pair(min,index));
    }
    for(int r=0;r<m;r++)
    {
        int i;
        for(i=0;i<m;i++)
        {
            if(r==i)
                continue;
            if(row_min[r].first<matrix[i][row_min[r].second])
                break;
        }
        if(i==m)
            ans.push_back(make_pair(r,row_min[r].second));
    }
    for(auto p:ans)
        cout<<"("<<p.first<<","<<p.second<<") ";
}



