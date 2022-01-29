bool dfs(AlberoB& nodo, int x, vector<int>& percorso) {
	if(nodo.nullo())
		return false;
	percorso.push_back(nodo.radice());
	if(nodo.foglia() && nodo->radice == x)
		return true;
	else if(dfs(nodo.figlio(SIN), x, percorso) || dfs(nodo.figlio(DES), x, percorso))
		return true;
	else {
		percorso.pop_back();
		return false;
	}
}

void esercizio1(AlberoB& radice, int x) {
	vector<int> percorso;

	if(dfs(radice, x, percorso)) {
		cout << percorso[0];
		for(int i = 1; i < percorso.size(); i++) {
			cout << " -> " << percorso[i];
		}
		cout << endl;
	}
	else
		cout << "-1" << endl;

}
