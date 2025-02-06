//const btn_novoFilme = document.getElementById('btn-new')

const btn_novoFilme = document.getElementById('btn-new')
const addFilme = document.getElementById('add-modal')
const backdrop = document.getElementById('backdrop')
const btnCancel = addFilme.querySelector('.btn--passive')
const btnAdd = btnCancel.nextElementSibling
const entrada = addFilme.querySelectorAll('input')

const filmes = [];


const toggleBackdrp = () => {
    backdrop.classList.toggle('visible')
}

const toggleModal = () => {
    addFilme.classList.toggle('visible')
    toggleBackdrp()
}

function cancelarAddFilme(){
    toggleModal()
}

function tratarClickBackdrop() {
    toggleModal()
}

function tratarNovoFilme() {
    const valortitulo = entrada[0].value
    const valorimagem = entrada[1].value
    const valorclass = entrada[2].value

    const novo = {
        titulo: valortitulo,
        imagem: valorimagem,
        classifica: valorclass
    }

    filmes.push(novo)
    toggleModal()
}

backdrop.addEventListener('click', tratarClickBackdrop)
btn_novoFilme.addEventListener('click', toggleModal)
btnCancel.addEventListener('click', cancelarAddFilme)
btnAdd.addEventListener('click', tratarNovoFilme)