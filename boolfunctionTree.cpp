//
//  main.cpp
//  boolfunctionTree.cpp
//
//  Created by fabio deo on 07/02/2018.
//  Copyright © 2018 fabio deo. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

struct bdnode{
    std::string val;
    bdnode* left;
    bdnode* right;
};

typedef bdnode* bdt;

bdt buildbdt(const std::vector<std::string>& fvalues);
std::string evalbdt(bdt t, const std::string& input);
void building_structure(bdt& hdtree, int height_of_x, int depth_of_x);
void setting_ones(bdt hdtree, const std::string& input);

//// FOR TESTING ONLY ////-----------------------------------------------
void generate_combinations(std::string current, int len, std::vector<std::string>& combinations){
    if(len == 0){
        combinations.push_back(current);
        return;
    }
    generate_combinations(current + "0", len - 1, combinations);
    generate_combinations(current + "1", len - 1, combinations);
}

void test_all(int len, bdt tree){
    std::vector<std::string> combinations;
    generate_combinations("", len, combinations);
    for(std::string combination: combinations)
        std::cout << combination << ": " << evalbdt(tree, combination) << std::endl;
}
////---------------------------------------------------------------------

int main(){
    //testing an or tree
    std::vector<std::string> input;
    std::string in = "111010";
    input.push_back(in);

    in = "010100";
    input.push_back(in);

    in = "001000";
    input.push_back(in);

    in = "000000";
    input.push_back(in);
    
    in = "101000";
    input.push_back(in);
    
    input.push_back(in);
    bdt hdtree = NULL;
    hdtree = buildbdt(input);
    
    int len = input[0].length();
    test_all(len, hdtree);
    
    return 0;
}

//returns the pointer to the tree created
bdt buildbdt(const std::vector<std::string>& fvalues){
    
    bdt hdtree = NULL;
    int height = fvalues[0].length();
    int depth = 0;
    
    building_structure(hdtree, height, depth);
    
    //for each input sequence call set_ones
    for (int i = 0; i < fvalues.size(); i++){
        std::string input = fvalues[i];
        setting_ones(hdtree, input);
    }

    return hdtree;
}


//traverses the tree and returns a string with the value stored in the leaf;
std::string evalbdt(bdt t, const std::string& input){
    int height = input.length();

    for (int i = 0; i < height; i++){
        if (input[i] == '0')
            t = t->left;
        
        else
            t = t->right;
        
    }

    return t->val;
}

//creates the tree from scratch with 0s in the leaf and xn in the roots
void building_structure(bdt& hdtree, int height_of_x, int depth_of_x){
    
    //new building block
    bdt tmptree = new bdnode;
    
    
    hdtree = tmptree; //hdtree is what is passed by reference and now points to the head of the tree that the function will build using tmptree

    
    //base case, if height = 0, leaf point to NULL and leaf value initialized to 0;
    if (height_of_x == 0){
        tmptree->val = "0";
        tmptree->left = NULL;
        tmptree->right = NULL;
    }
    
    else{
        tmptree->val = "x" + std::to_string(depth_of_x);
        //every node has to have value = x_depth;
        
        
        //recursively build left and right subtrees (height decreases by 1, depth increases by 1)
        building_structure(tmptree->left, height_of_x - 1, depth_of_x + 1);
        building_structure(tmptree->right, height_of_x - 1, depth_of_x + 1);
    }
    
}

void setting_ones(bdt hdtree, const std::string& input){
    int height = input.length();

    //...travers the tree...
    for (int j = 0; j < height; j++){
        
        if (input[j] == '0')
            hdtree = hdtree->left;
            
        else
            hdtree = hdtree->right;
        
    }
    //...and overwrite a 1 in the leaf
    hdtree->val = "1";
    
}


