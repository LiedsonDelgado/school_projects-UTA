let array=[1,2,3];
array.push(4,5); //adiciona 4 e 5 ao array
console.log(array); //array atualizado para [1,2,3,4,5]

let array=[1,2,3,4,5];
array.pop; //remove o ultimo do array nesse caso sera o 5
console.log(array); //array atualizado para [1,2,3,4]

let array=[1,2,3];
array.shift(); // remove o 1 do array
console.log(array); //array atualizado para [2,3]

let array=[1,2,3];
array.unshift(0); //adiciona 0 ao inicio do vetor
console.log(array); //atualiza o vetor para [0,1,2,3]

let array_1=[1,3,5];
let array_2=[2,4,6];
let new_array=array_1.concat(array_2); //a combinacao dos dois arrays
console.log(new_array);//novo vetor resultado da combinacao de
                      // array_1 e array_2

let array=[1,2,3,4];
array.splice(1,1);//remove um elemento apartir do indice 1(i=1)
                 //remove o elemento 2
console.log(array);//atualiza o vetor para [1,3,4]

let array=[1,2,3,4,5,6];
new_array=array.slice(1,4);//extrai elementos do indice 1 ao 4(i=[1,4])
console.log(new_array); //retorna um novo vetor para com os elementos [1,6]
                       //extraidos apartir dos indices indicados

let array=[1,2,3];
let return_indexOf=array.indexOf(3); //faz a procura do elemento 3
console.log(return_indexOf); //retorna o indice de 3(i=2)

let array=[1,2,3,4,5,6];
let quadrado=array.map(val=>val*val); //faz o quadrado cada elemento ou seja [1*1,2*2,3*3,4*4,5*5,6*6]  
console.log(quadrado); //retorna o novo array apartir da operacao com os elementos do array incial
                      //[1,4,9,16,25,36]

let notas=[3,6,9,14,15,17,19.2,13];
let estado_aluno=notas.filter(val =>{ //compara os valores do array para ver qual satisfaz a condicao
    if(val>=10){
        console.log("Aprovado");
    }else{
        console.log("Reprovado");
    }
});
console.log(estado_aluno); // retorna um novo vetor com os elementos que satisfizeram as condicoes
                          //[13,14,15,17,19.2]
    