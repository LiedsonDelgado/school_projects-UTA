//TP1-Liedson Delgado-LEIT
import robocode.*;

public class DefenseRobot extends Robot{ //Classe que implementa um robo focado em defesa
    public void run(){
        while(true){
            turnLeft(90);
            ahead(150);
            turnRight(90);
            ahead(150);
        }
    }

    public void onHitByBullet(HitByBulletEvent evento){
        back(50);
        turnRight(90);
        ahead(50);
    }

    public void onScannedRobot(ScannedRobotEvent evento){
        if(evento.getDistance()<100){
            fire(2);
        }
    }
}

//comando para compilar no terminal vscode: javac -cp lib/robocode.jar src/MyRobot.java