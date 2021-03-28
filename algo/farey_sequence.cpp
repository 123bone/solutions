vector<pair<int,int>> farey;
 
// gen n'th Farey sequence https://en.wikipedia.org/wiki/Farey_sequence#Next_term
void gen_farey(int n){
    int a = 0, b = 1; // first 2 terms: (0/1, 1/n)
    int c = 1, d = n;
    farey.push_back({0,1});
    
    while(c <= n){
        farey.push_back({c,d});
        int k = (n + b) / d;
        int p = k*c - a, q = k*d - b;
        a = c, b = d;
        c = p, d = q;
    }
}
