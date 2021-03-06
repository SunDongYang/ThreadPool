/*线程池拥有若干个线程

用于执行大量的相对短暂的任务

计算密集型任务：	线程个数 = CPU个数
I/O密集型任务：		线程个数 > CPU个数
*/

// 用于执行大量相对短暂的任务
//
// 当任务增加的时候能够动态的增加线程池中的数量直到达到一个阈值
//
// 当任务执行完毕的时候，能够动态的销毁线程池中的线程
//
// 该线程池的实现本质上也是生产者消费者模型的应用。生产者线程向任务队列
// 中添加任务，一旦队列有任务到来，如果有等待线程就唤醒来执行任务，如果
// 没有等待线程并且线程的数量没有达到阈值，就创建新线程来执行任务
