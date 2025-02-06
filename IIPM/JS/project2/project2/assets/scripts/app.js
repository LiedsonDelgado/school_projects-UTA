let VALOR_ATAQUE_PLAYER = 10;
let VALOR_ATAQUE_ESPECIAL_PLAYER = 17;
let VALOR_ATAQUE_MONSTRO = 14;

let VALOR_RECUPERACAO_PLAYER = 8;
let LIFE_POTION = 2;

let maxHP = 100;

let playerHP_bonus = true;
let playerHP = maxHP;
let monsterHP = maxHP;

let damage_value_p;
let damage_value_m;

const valorMaxDigitado = prompt('Digite o valor maximo de vida');

let valorMaximoVidaDigitado = parseInt(valorMaxDigitado);

if(isNaN(valorMaxDigitado) || valorMaxDigitado<=0){
    maxHP = maxHP;
}else {
    maxHP = valorMaxDigitado;
}

adjustHealthBars(maxHP);

const ataque = (tipo) => {

    if(tipo === 'VALOR_ATAQUE_PLAYER'){
        damage_value_m=VALOR_ATAQUE_PLAYER;

    }else if(tipo === 'VALOR_ATAQUE_ESPECIAL_PLAYER'){
        damage_value_m=VALOR_ATAQUE_ESPECIAL_PLAYER;
    }

    damage_value_m=dealMonsterDamage(damage_value_m);
        monsterHP-=damage_value_m;

        let enterLog = {
            event: tipo,
            valor: damage_value_m,
            monsterHP_value:monsterHP,
            playerHP_value:playerHP
        }

}

const gameState = () => {
    const valueHP_aux=playerHP;
    const damage_on_player=dealPlayerDamage(VALOR_ATAQUE_MONSTRO);

    playerHP-=damage_value_p;

    if(monsterHP<=0 && playerHP>0){
        alert('O Jogador Venceu');
    }else if(playerHP<=0 && monsterHP>0){
        alert('O Jogador Perdeu');
    }else if(playerHP<=0 && monsterHP<=0){
        alert('Empate');
    }
}

function strongAttackHandler() { /*Dps impor condicao max de ataque especial do jogador*/
        const special_damage_m = dealMonsterDamage(VALOR_ATAQUE_ESPECIAL_PLAYER);

            monsterHP-=special_damage_m;
            playerHP-=damage_value_p;
}

function healPlayer(){ /*Dps impor condicao max de recuperacao do jogador*/
    if(LIFE_POTION > 0 || playerHP > 0){
        const heal_value_p = increasePlayerHealth(VALOR_RECUPERACAO_PLAYER);
            playerHP+=heal_value_p;
                LIFE_POTION=LIFE_POTION-1;
        console.log(`[+]Jogador usou uma Pocao, restam: ${LIFE_POTION}`);
    }else{
        alert('Pocoes de Vida Acabaram');
    }
}

attackBtn.addEventListener('click',ataque);
strongAttackBtn.addEventListener('click',strongAttackHandler);
healBtn.addEventListener('click',healPlayer);
logBtn.addEventListener('click',() => {console.log(enterLog)})