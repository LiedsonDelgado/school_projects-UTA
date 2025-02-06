const disciplinas = [
    { nome: "Análise Matemática", ano: 1, classificacao: 16 },
    { nome: "Física", ano: 1, classificacao: 14 },
    { nome: "Sistemas Digitais", ano: 2, classificacao: 17 },
    { nome: "Programação", ano: 2, classificacao: 18 },
    { nome: "Estatística", ano: 3, classificacao: 15 },
    { nome: "Inteligência Artificial", ano: 3, classificacao: 19 }
];

function filtrarDisciplinasPorAno(ano) {
    return disciplinas.filter(disciplina => disciplina.ano === ano);
}

function calcularMediaClassificacoes() {
    const totalClassificacao = disciplinas.reduce((soma, disciplina) => soma + disciplina.classificacao, 0);
    return totalClassificacao / disciplinas.length;
}

function listarNomesDisciplinas() {
    return disciplinas.map(disciplina => disciplina.nome);
}

function ordenarDisciplinasPorClassificacao() {
    return [...disciplinas].sort((a, b) => a.classificacao - b.classificacao);
}

function verificarDisciplinaFrequentada(nomeDisciplina) {
    return disciplinas.some(disciplina => disciplina.nome.toLowerCase() === nomeDisciplina.toLowerCase());
}

console.log("Disciplinas do ano 2:", filtrarDisciplinasPorAno(2));
console.log("Média das classificações:", calcularMediaClassificacoes());
console.log("Lista de nomes das disciplinas:", listarNomesDisciplinas());
console.log("Disciplinas ordenadas por classificação:", ordenarDisciplinasPorClassificacao());
console.log("A disciplina 'Programação' foi frequentada?", verificarDisciplinaFrequentada("Programação"));
console.log("A disciplina 'Biologia' foi frequentada?", verificarDisciplinaFrequentada("Biologia"));
