bool sudoku2(std::vector<std::vector<char>> grid) {
    
    int n = grid[0].size();
    int dim = 3;
    int maxGrids = n/dim;

    /* check single lines first */
    for ( int i = 0; i < n; i++ ) {
        std::map<int,int> digits;
        for ( int j = 0; j < n; j++ ) {
            if ( grid[i][j] != '.') {
                int val = grid[i][j] - '0';
                std::map<int,int>::iterator it;
                it = digits.find(val);
                if ( it != digits.end() ) {
                    std::cout << "i: " << i << "; j: " << j << std::endl;
                    return false;
                }
                digits.insert(std::pair<int,int>(val,1));
            }          
        }       
    }
    
    /* check single columns */
    for ( int i = 0; i < n; i++ ) {
        std::map<int,int> digits;
        for ( int j = 0; j < n; j++ ) {
            if ( grid[j][i] != '.') {
                int val = grid[j][i] - '0';
                std::map<int,int>::iterator it;
                it = digits.find(val);
                if ( it != digits.end() ) {
                    std::cout << "i: " << i << "; j: " << j << std::endl;
                    return false;
                }
                digits.insert(std::pair<int,int>(val,1));
            }    
        }
    }
    
    int minRow = 0;
    int maxRow = dim;
    int shift = 0;
    int count = 0;
    
    while (shift < 9) {
        count = 0; 
        int minCol = 0;
        int maxCol = dim;
        minRow = shift;   
        maxRow = shift + dim;  
        while (count < 3) {
            std::map<int,int> digits;
            for ( int i = minRow; i < maxRow; i++ ) {  
                for ( int j = minCol; j < maxCol; j++ ) { 
                    if ( grid[i][j] != '.') {
                        int val = grid[i][j] - '0';
                        std::map<int,int>::iterator it;
                        it = digits.find(val);
                        if ( it != digits.end() ) {
                            return false;
                        }
                        digits.insert(std::pair<int,int>(val,1));
                    }     
                }               
            }
            minCol += dim;
            maxCol += dim;
            count++;
        }
        shift += dim;
    }

    return true;     
}
