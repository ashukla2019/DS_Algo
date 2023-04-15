//Reverse word in given string:
Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i

string reverseWords(string S) 
{ 
 istringstream iss(S);
 string rtr = "";
 string token;
 while (std::getline(iss, token, '.')) 
 {
     if (!token.empty())
     {
	rtr = token + "." + rtr;

    }

}
rtr.pop_back();
return rtr;
} 
