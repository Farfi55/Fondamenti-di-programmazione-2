// 09-12-2021 15:54
struct Tsoluzione {
    Grafo G;
    vector<int> s;
}

bool canAdd(int x, const Tsoluzione& sol) {
    if(find(x, sol.s.begin(), sol.s.end()) != sol.s.end()) return false;
    for(int i = 0; i < sol.s.size(); i++)
        if(sol.G(sol.s[i], x) || sol.G(x, sol.s[i])) return false;

    return true;
}

bool isComplete(const Tsoluzione& sol) {
    for(int i = 0; i < sol.G.n(); i++)
        if(find(i, sol.s.begin(), sol.s.end()) == sol.s.end()) {
            bool esisteArco = false; //VERIFICA SE ESISTE L'ARCO
            for(int j = 0;j < sol.s.size(); j++)
                if(sol.G(sol.s[j], i)) esisteArco = true;
            if(!esisteArco) return false;
        }
    return true;
}


bool solve(Tsoluzione& sol) {
    x = 0;
    while(x < sol.G.n())
        if(canAdd(x, sol)) {
            add(x, sol); //aggiungi x in coda a sol 
            if(isComplete(sol)) return true;
            else if(solve(sol)) return true;
            remove(x, sol); x++; //backtrack 
        }
        else
            x++;
    return false;

}
