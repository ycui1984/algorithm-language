/*
You have a large text file containing words. Given any two words, find the
shortest distance (in terms of number of words) between them in the file. If the
operation will be repeated many times for the same file (but different pairs of
words), can you optimize your solution?
*/

int real_min(unordered_map<string, vector<int> > &map, string w1, string w2) {
	int min = INT_MAX;
	int start1 = 0, start2 = 0; int tmp_min;
	for (start1 = 0; start1 < map[w1].size(); start1++) {
		tmp_min = INT_MAX;
		for (start2 = 0; start2 < map[w2].size(); start2++) {	
			int tmp = abs(map[w1][start1] - map[w2][start2]);
			if (tmp < tmp_min) { 
				tmp_min = tmp;
				if (tmp_min < min) min = tmp_min;
			} else break;	
		}
		
	}

	return min;
}

struct data {
	int value;
	int tag;
};

bool compare(struct data d1, struct data d2) {
	return d1.value < d2.value;	
}

int real_min_v2(unordered_map<string, vector<int> > &map, string w1, string w2) {
	int min = INT_MAX;
	int vector<struct data> tmp;
	for (int i = 0; i<map[w1].size(); i++) {
		struct data d;
		d.value = map[w1][i];
		d.tag = 0;
		tmp.push_back(d);
	}

	for (int i = 0; i<map[w2].size(); i++) {
		struct data d;
		d.value = map[w2][i];
		d.tag = 1;
		tmp.push_back(d);
	}

	sort(tmp.begin(), tmp.end(), compare); 
	for (int s = 0; i < tmp.size() - 1; i++) {
		if (tmp[s].tag != tmp[s + 1].tag) {
			if (tmp[s + 1].value - tmp[s].value < min) 
				min = tmp[s + 1].value - tmp[s].value;
		}
	}

	return min;
}

int get_min(vector<string> &book, string w1, string w2) {
	unordered_map<string, vector<int> > map;
	for (int i = 0; i < book.size(); i++) 
		map[book[i]].push_back(i);

	if (0 == map[w1].size() || 0 == map[w2].size()) 
		return INT_MAX;

	return real_min(map, w1, w2);
}
