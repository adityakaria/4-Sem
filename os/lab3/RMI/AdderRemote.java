import java.rmi.*;  
import java.rmi.server.*;  

public class AdderRemote extends UnicastRemoteObject implements Adder{  
    AdderRemote()throws RemoteException{  
        super();  
    }  
    public int add(int x,int y){
        return x+y;
    }  
}  


// to make stub and skeleton objects using 'rmic': $ rmic remote_ask

// Start the registry service by issuing the following command at the command prompt: $ start rmiregistry