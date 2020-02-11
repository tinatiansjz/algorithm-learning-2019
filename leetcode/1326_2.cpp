#include <vector>
using namespace std;
int minTaps(int n, vector<int>& ranges) 
{
	vector<int> land(n);
	for (int i = 0; i < ranges.size(); i++)
	{
		int l = max(i - ranges[i], 0);
		int r = min(i + ranges[i], n);
		for (int j = l; j < r; j++)
		{
			land[j] = max(land[j], r);
		}
	}

	int cnt = 0;
	int cur = 0;
	while (cur < n)
	{
		if (land[cur] == 0) return -1;
		cur = land[cur];
		cnt++;
	}
	return cnt;
}