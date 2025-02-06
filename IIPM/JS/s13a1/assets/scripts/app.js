const VALOR_ATAQUE = 10;
const VALOR_ATAQUE_STRONG = 17;
const VALOR_ATAQUE_MONSTRO = 14;
const VALOR_RECUPERA = 20;

let valorMaximoVida = 100;
let valorVidaMonstro = valorMaximoVida;
let valorVidaPlayer = valorMaximoVida;

adjustHealthBars(valorMaximoVida);


function attackHandler() {
 
  const dano = dealMonsterDamage(VALOR_ATAQUE);
  valorVidaMonstro -= dano;

  const danoNoJogador = dealPlayerDamage(VALOR_ATAQUE_MONSTRO);
  valorVidaPlayer -= danoNoJogador;
  if (valorVidaMonstro <= 0 && valorVidaPlayer > 0) {
    alert('Você venceu!');
  } else if (valorVidaPlayer <= 0 && valorVidaMonstro > 0) {
    alert('Você perdeu!');
  } else if (valorVidaMonstro <= 0 && valorVidaMonstro <= 0) {
    alert('Empate!');
  }

}

function strongAttackHandler() {
  
  const dano = dealMonsterDamage(VALOR_ATAQUE_STRONG);
  valorVidaMonstro -= dano;

  const danoNoJogador = dealPlayerDamage(VALOR_ATAQUE_MONSTRO);
  valorVidaPlayer -= danoNoJogador;
  if (valorVidaMonstro <= 0 && valorVidaPlayer > 0) {
    alert('Você venceu!');
  } else if (valorVidaPlayer <= 0 && valorVidaMonstro > 0) {
    alert('Você perdeu!');
  } else if (valorVidaMonstro <= 0 && valorVidaMonstro <= 0) {
    alert('Empate!');
  }
}

function healPlayerHandler() {
  let vRecupera;
  if (valorVidaPlayer >= valorMaximoVida - VALOR_RECUPERA) {
    alert("Recuperar não pode ser superior saúde inicial máxima.");
    vRecupera = valorMaximoVida - valorVidaPlayer;
  } else {
    vRecupera = VALOR_RECUPERA;
  }
  increasePlayerHealth(vRecupera);
  valorVidaPlayer += vRecupera;
 
}

attackBtn.addEventListener('click', attackHandler);
strongAttackBtn.addEventListener('click', strongAttackHandler);
healBtn.addEventListener('click', healPlayerHandler);