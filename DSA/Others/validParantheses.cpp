// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     string s;cin>>s;
//     stack<char> myStack;
//     int counter = 0;
//     int i = 0;
//     int answer = -1;
//     while(true){
//         if(i>=s.length()) break;
//         if(s[i] == '('){
//             myStack.push(s[i]);
//         }
//         else{
//             if(myStack.empty()){
//                 counter = 0;
//             }
//             else if(!myStack.empty()){
//                 counter+=2;
//                 myStack.pop();
//                 answer = max(answer,counter);
//                 cout<<answer<<" "<<i<<endl;
//             }

//         }        
//         i++;
//     }
//     cout<<answer<<endl;
// }
// // // C++ program to find length of the 
// // // longest valid substring
// // #include <bits/stdc++.h>
// // using namespace std;

// // int findMaxLen(string str)
// // {
// // 	int n = str.length();

// // 	// Create a stack and push -1 as 
// // 	// initial index to it.
// // 	stack<int> stk;
// // 	stk.push(-1);

// // 	// Initialize result
// // 	int result = 0;

// // 	// Traverse all characters of given string
// // 	for (int i = 0; i < n; i++)
// // 	{
// // 		// If opening bracket, push index of it
// // 		if (str[i] == '(')
// // 			stk.push(i);
		
// // 		// If closing bracket, i.e.,str[i] = ')'
// // 		else
// // 		{
// // 			// Pop the previous opening
// // 			// bracket's index
// // 			if (!stk.empty()) 
// // 			{
// // 				stk.pop();
// // 			}
			
// // 			// Check if this length formed with base of
// // 			// current valid substring is more than max
// // 			// so far
// // 			if (!stk.empty())
// // 				result = max(result, i - stk.top());

// // 			// If stack is empty. push current index as
// // 			// base for next valid substring (if any)
// // 			else
// // 				stk.push(i);
// // 		}
// // 	}

// // 	return result;
// // }

// // // Driver code
// // int main()
// // {
// // 	string str = "()()(((";

// // 	// Function call
// // 	cout << findMaxLen(str) << endl;

// // 	str = "()(()))))";

// // 	// Function call
// // 	cout << findMaxLen(str) << endl;

// // 	return 0;
// // }
// C++ program to find length of the 
// longest valid substring
#include <bits/stdc++.h>
using namespace std;
 
int findMaxLen(string str)
{
    int n = str.length();
 
    // Create a stack and push -1 as 
    // initial index to it.
    stack<int> stk;
    stk.push(-1);
 
    // Initialize result
    int result = 0;
 
    // Traverse all characters of given string
    for (int i = 0; i < n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);
         
        // If closing bracket, i.e.,str[i] = ')'
        else
        {
            // Pop the previous opening
            // bracket's index
            if (!stk.empty()) 
            {
                stk.pop();
            }
             
            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!stk.empty())
                result = max(result, i - stk.top());
 
            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else
                stk.push(i);
        }
    }
 
    return result;
}
 
// Driver code
int main()
{
    string str = "((()()";
   
    // Function call
    cout << findMaxLen(str) << endl;
 
    str = "()()(((";
   
    // Function call
    cout << findMaxLen(str) << endl;
 
    return 0;
}