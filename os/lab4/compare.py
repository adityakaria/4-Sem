# Python3 program for implementation  
# of FCFS scheduling 
  
def findWaitingTimefcfs(processes, n, bt, wt): 
  
    wt[0] = 0
  
    for i in range(1, n ): 
        wt[i] = bt[i - 1] + wt[i - 1]  
  
def findTurnAroundTimefcfs(processes, n, bt, wt, tat): 
  
    for i in range(n): 
        tat[i] = bt[i] + wt[i] 
  
def findavgTimefcfs( processes, n, bt): 
  
    wt = [0] * n 
    tat = [0] * n  
    total_wt = 0
    total_tat = 0
  
    findWaitingTimefcfs(processes, n, bt, wt) 
  
    findTurnAroundTimefcfs(processes, n,  
                       bt, wt, tat) 
  
    print( "Processes Burst time " + 
                  " Waiting time " + 
                " Turn around time") 
  
    for i in range(n): 
      
        total_wt = total_wt + wt[i] 
        total_tat = total_tat + tat[i] 
        print(" " + str(i + 1) + "\t\t" + 
                    str(bt[i]) + "\t " + 
                    str(wt[i]) + "\t\t " + 
                    str(tat[i]))  
  
    print( "Average waiting time = "+
                   str(total_wt / n)) 
    print("Average turn around time = "+
                     str(total_tat / n))

def findWaitingTimerr(processes, n, bt,  
                         wt, quantum):  
    rem_bt = [0] * n 

    for i in range(n):  
        rem_bt[i] = bt[i] 
    t = 0 # Current time  
  
  
    while(1): 
        done = True
  
        for i in range(n): 
                
            if (rem_bt[i] > 0) : 
                done = False # There is a pending process 
                  
                if (rem_bt[i] > quantum) : 
                   
                    t += quantum  
   
                    rem_bt[i] -= quantum  
                  
                else: 
                  
                    t = t + rem_bt[i]  
    
                    wt[i] = t - bt[i]  
  
                    rem_bt[i] = 0
                  
        # If all processes are done  
        if (done == True): 
            break
              
def findTurnAroundTimerr(processes, n, bt, wt, tat): 
      
    for i in range(n): 
        tat[i] = bt[i] + wt[i]  
  
    
def findavgTimerr(processes, n, bt, quantum):  
    wt = [0] * n 
    tat = [0] * n  
  
    findWaitingTimerr(processes, n, bt,  
                         wt, quantum)  
  
    findTurnAroundTimerr(processes, n, bt, 
                                wt, tat)  
  
    print("Processes   Burst Time    Waiting     Time   Turn-Around Time") 
    total_wt = 0
    total_tat = 0
    for i in range(n):
        total_wt = total_wt + wt[i]  
        total_tat = total_tat + tat[i]  
        # print(" ", i + 1, " ", bt[i], "\t", wt[i], "\t", tat[i]) 
        print(" "+ str(i + 1)+ "            "+ str(bt[i])+ "            " + str(wt[i])+ "           "+ str(tat[i])) 

  
    print("\nAverage waiting time = %.5f "%(total_wt /n) ) 
    print("Average turn around time = %.5f "% (total_tat / n))  
  
if __name__ =="__main__": 
      
    processes = [ 1, 2, 3, 4, 5] 
    n = len(processes) 
   
    burst_time = [10, 29, 3, 7, 12] 
  
    findavgTimefcfs(processes, n, burst_time) 
    
    proc = [ 1, 2, 3, 4, 5] 
    n = 5
    
    burst_time = [10, 29, 3, 7, 12]  
  
    # Time quantum  
    quantum = 5;  
    findavgTimerr(proc, n, burst_time, quantum) 