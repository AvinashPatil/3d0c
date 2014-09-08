Thread Pool Implementation
===========================

* Creates a thread pool.
* Enqueues the job items
* Threads consume the job items and execute the function specified in the job.
* After finishing with jobs i.e when queue is empty, the threads exit themseves.

Future enhancements
==================

* Resize the queue.
* Increase number of threads based on load.

