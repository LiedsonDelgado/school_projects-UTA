/*CORRIGIR ERRO DO RESULTADO*/

let listarRegistros = [];
let resultado = 0;
const resultadoCorrente = resultado;

const aluno = { /*Objeto aluno*/
    code: '00010001',
    nome: 'John',
    curso: 'LEIT',
    ano: '2',
}

function readInput(){
   const valor_digitado = parseInt(userInput.value);
    return valor_digitado;
}

function getUserNumberInput(){
    return parseInt(userInput.value);
}

function escreverRegistro(operador,resultadoAnterior,operando,resultado){
    const entradaRegistro = {
        operador: operador,
        resultado: resultadoAnterior,
        numero: operando,
        resultado: resultado,
}
    console.log(entradaRegistro);
}

const realizarCalculo=(operador) => {
if(operador ==='ADD'){
    const valor_lido = readInput();

    const description  = `${resultado} + ${valor_lido}`;
    resultado = resultado + valor_lido;
    outputResult(resultado,description);

    const entradaRegistro = {
            operador: operador,
            resultadoAnt: resultadoAnterior,
            numero: operando,
            resultado
    }
    listarRegistros.push(entradaRegistro);
    console.log(entradaRegistro);

    escreverRegistro("ADD",resultado,valor_lido,resultadoCorrente);
/*===============================================================================================*/
}else if(operador ==='MUL'){
    const valor_lido = readInput();

    const description  = `${resultado} * ${valor_lido}`;
    resultado = resultado * valor_lido;
    outputResult(resultado,description);

    escreverRegistro("MUL",resultado,valor_lido,resultadoCorrente);
/*===============================================================================================*/
}else if(operador ==='SUB'){
    const valor_lido = readInput();

    const description  = `${resultado} - ${valor_lido}`;
    resultado = resultado - valor_lido;
    outputResult(resultado,description);

    escreverRegistro("SUB",resultado,valor_lido,resultadoCorrente);
/*===============================================================================================*/      
}else if(operador ==='DIV'){
    const valor_lido = readInput();
    
if(valor_lido !== 0){
    const description  = `${resultado} / ${valor_lido}`;
    
    outputResult(resultado,description);
/*===============================================================================================*/
}else{
    alert("Erro ao dividir valor por 0");
}

    escreverRegistro("DIV",resultado,valor_lido,resultadoCorrente);
}else{
    alert('Operacao Invalida');
}
}

function adicionar(){
    realizarCalculo('ADD');
}

function multiplicar(){
    realizarCalculo('MUL');
}

function subtrair(){
    realizarCalculo('SUB');
}

function dividir(){
    realizarCalculo('DIV');
}

addBtn.addEventListener("click", adicionar);
multiplyBtn.addEventListener("click", multiplicar);
subtractBtn.addEventListener("click", subtrair);
divideBtn.addEventListener("click", dividir);