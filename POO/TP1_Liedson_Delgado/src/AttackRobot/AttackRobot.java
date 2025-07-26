//TP1-Liedson Delgado-LEIT
import robocode.*;

public class AttackRobot extends Robot{ //Classe que implementa um robo focado em ataque
    public void run(){
        while(true){
            ahead(100);
            turnGunRight(360);
            back(100);
            turnGunRight(360);
        }
    }

    public void onScannedRobot(ScannedRobotEvent evento){
        fire(3);
    }

    public void onHitByBullet(HitByBulletEvent evento){
        turnRight(90-evento.getBearing());
        ahead(100);
    }
}

//comando para compilar no terminal vscode: javac -cp lib/robocode.jar src/MyRobot.java