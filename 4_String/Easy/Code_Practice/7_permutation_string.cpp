//Permutations of a given string :
Input: ABC
Output: ABC ACB BAC BCA CAB CBA
vector<string>find_permutation(string str)
{
     vector<string> s;
     sort(str.begin(), str.end());  
     do
     {
     	s.push_back(str);
     }while(next_permutation(str.begin(),str.end()));
     return s;
}
