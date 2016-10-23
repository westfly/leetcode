int firstUniqChar(string s) {
	int size = s.size();
	// may long 
	int char_map[256] = {0};
	for (int i = 0; i < size; ++i) {
			char_map[s[i]] ++;
	}
	for (int i = 0; i < size; ++i) {
			if (char_map[s[i]] == 1) {
					return i;
			}
	}
	return -1;
}
