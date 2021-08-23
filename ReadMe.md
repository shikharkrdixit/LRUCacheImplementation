#### LRU Cache Implementation

LRU Stands for **Least Recently Used**. Here I have implemented a least recently used Caching system which sorts the system based on how recently each Element is being used.

Whenever, a process calls for an element, the system looks into the Cache if it exists there the system is returned. But if it is not present their the processor then looks into the Disk which takes longer time compared to that of the Caching System. Whenever, the cache becomes full the item least recently used is removed out of the Cache and a new item is included.

This LRU Cache can be implemented using a Hashmap and a Doubly Linked List, though here we have used a list and a hashmap.

The Hashmap consists of the Key and the Address of the corresponding Node, and the List contains the node with the Key and it's value.

***


Header files used :


Header files | 
------------- | 
iostream  |
list | 
unordered_map |

***

**Made with ❤️ by [Shikhar](https://www.linkedin.com/in/shikharkrdixit/) .**


[<img src='https://camo.githubusercontent.com/5fca3db52c463447c36cbf864b01eac247219e56ce24dc0169a66c62ae53a481/68747470733a2f2f6d656469612e67697068792e636f6d2f6d656469612f6475334a336358797a686a3735494f6776412f67697068792e676966' alt='github' height='40'>](https://github.com/shikharkrdixit)