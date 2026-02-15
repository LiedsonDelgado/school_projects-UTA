# C-Trivia

![c](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![](https://img.shields.io/badge/MIT-green?style=for-the-badge)
![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/TiagoDongo/C-Trivia/compileProject.yml?branch=main&style=for-the-badge&logo=githubactions&logoColor=%23fff&logoSize=auto&label=Compile%20Project&labelColor=%23242526)

Projeto se trata de um **jogo de perguntas e  respostas (Trivia / Quiz)** desenvolvido em linguagem **C**.

> [!NOTE]
>
> **Prerequisitos**
> - **Windows**:  
>   - Instale [`MinGW`](https://sourceforge.net/projects/mingw/).  
>   - Adicione `gcc` aos caminhos do sistema.  
>   - *Opcional*: Dupliqui `mingw32-make.exe` e o renomeie para `make`.  
> - **Linux**:  
>   ```bash  
>   sudo apt update && sudo apt install build-essential
>   ```

## Compilação e Execução
- **Compilação:**
    ```
    make ou mingw32-make 
    ```
- **Execução:**
    ```
    make run ou mingw32-make run
    ```
- **Ajuda:** em caso de ajuda digite o seguinte no terminal
    ```
    make help ou mingw32-make help
    ```

## Padrão de Commits
- `feat:` Nova funcionalidade
- `fix:` Correção de bug  
- `docs:` Documentação
- `style:` Formatação (espaços, vírgulas)
- `refactor:` Refatoração sem mudar comportamento
- `test:` Adição ou correção de testes
- `chore:` Tarefas de manutenção
- `ci`: adição de workflows