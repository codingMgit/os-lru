<b>
LRU (Least Recently Used) Page Replacement Algorithm
  
Aim
Implement the Least Recently Used page replacement algorithm for memory management.

Description
LRU replaces the page that has not been used for the longest time, based on historical page access patterns.

Algorithm

Initialize page frames with -1
For each page in the reference string:

If page not in frame, increment page fault
If frame not full, add page
If frame full, replace least recently used page


Track and display page faults
</b>