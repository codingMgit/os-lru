<b>
LRU (Least Recently Used) Page Replacement Algorithm
  
Aim:

Implement the Least Recently Used page replacement algorithm for memory management.

Description:

LRU replaces the page that has not been used for the longest time, based on historical page access patterns.

Algorithm:

Initialize page frames with -1
For each page in the reference string:

If page not in frame, increment page fault
If frame not full, add page
If frame full, replace least recently used page


Track and display page faults

Output :

Enter the number of pages (<1000):
10
Enter 10 pages:
1 2 3 4 3 2 1 1 1 3
Enter the number of frames (<100):
4
PAGE FAULTS = 4
</b>
