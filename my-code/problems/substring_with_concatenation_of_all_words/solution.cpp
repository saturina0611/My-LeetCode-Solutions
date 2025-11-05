class Solution
{
public:
	// map<int , bool> mp[(int)1e4 + 5];
	map<string, int> freq;
	map<string, int> id;
	int mp2[(int)1e4 + 5];
	int e[(int)1e4 + 5];
	bool other[(int)1e4 + 6];
	map<int, vector<int>> vt;
	vector<int> findSubstring(string s, vector<string> & words)
	{
		memset(other, 1, sizeof other);
		vector<int> ans;
		int len = words[0].size();
		for (int i = 0; i <= 1e4 + 3; i++)
			mp2[i] = -1;
		int dem = 0;
		string str;
		for (int i = 0; i < words.size(); i++)
		{
			freq[words[i]]++;
			if (freq[words[i]] == 1)
				id[words[i]] = ++dem;
		}
		for (int i = 0; i + len - 1 < s.size(); i++)
		{
			if (i == 0)
			{
				for (int j = i; j <= i + len - 1; j++)
					str.push_back(s[j]);
			}
			else
			{
				str.erase(str.begin());
				str.push_back(s[i + len - 1]);
			}
			for (int j = 0; j < words.size(); j++)
			{
				if (str == words[j])
					mp2[i] = j;
			}
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (other[i] == 0)
				continue;
            if(mp2[i] == -1) continue;
			other[i] = 0;
			int itr = i;
			int cnt = 0;
			vector<int> past;
			deque<int> someitr;
            int bd = itr;
			while (1)
			{
				bool check = 1;
				while (mp2[itr] != -1)
				{
                    //cout << itr << ' ' << mp2[itr] << '\n';
                    //if(!someitr.empty() && itr == someitr.back()) break;
                    if (e[id[words[mp2[itr]]]] >= freq[words[mp2[itr]]])
					{
						check = 0;
						break;
					}
					other[itr] = 0;
					someitr.push_back(itr);
					
					e[id[words[mp2[itr]]]]++;
					if (e[id[words[mp2[itr]]]] == 1)
						past.push_back(id[words[mp2[itr]]]);
					itr += len;
					cnt++;
					if (cnt == words.size())
					{
						ans.push_back(bd);
						break;
					}
				}
				// for(auto it : past) e[it] = 0;
				if (1)
				{
                    //cout << bd << ' ' << itr << '\n';
                    // deque<int> someitr2 = someitr;
                    // while(!someitr2.empty()) {
                    //     cout << someitr2.front() << ' ';
                    //     someitr2.pop_front();
                    // }
                    // cout << '\n';
					int x = someitr.front();
                    e[id[words[mp2[x]]]]--;
					someitr.pop_front();
                    cnt--;
                    if(!someitr.empty()) bd = someitr.front();
                    else break;
                    //if(mp2[itr] != -1) itr += len;
				}
			}
		}
		return ans;
	}
};