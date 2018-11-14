# Table of Contents

1. [Contribuindo](#Contribuindo)
2. [Politica de commits](#Commits)
3. [Politica de Pr's](#Pr's)
4. [Requerimentos](#Requerimentos)


## Contribuindo

1. Crie uma *issue* com uma melhoria/*bug* ou adote uma das *issues* já existentes.
2. Crie uma *branch* chamada ``dev_[feature]``, onde *feature* é o nome ou número de uma *issue* a ser trabalhada.
3. Atualize a *branch* ``dev_[feature]`` com seu código de acordo com a [folha de estilos](https://google.github.io/styleguide/cppguide.html) utilizada, e envie seus *commits* de acordo com a [politica de commits](#commits)
4. Rode os tests para ver se tudo está de acordo com o previsto:
  ```bash
  make test
  ./test
  ```
4. Após sucesso em todo os tests, de um *push* com suas modifições para sua *branch*, de um *pull* na master, resolva os conflitos e crie um [PR](#pr's) (Pull Resquest) para a master.

### Commits

* Commits feitos em português.

* Um commit bom deve sempre ser capaz de completar a seguinte frase:

> *se aplicado, esse commit ira [commit message]*

* Exemplo prático:

```git
Corrige bug no arquivo Models.cpp
Adicionar importação de funcionalidades de projeto
```

* Utilize **imperativo**, não gerúndio!

### Pr's

#### 1º Passo
- Preencher o Título do _Pull Request_, uma sucinta descrição a respeito do _Pull Request_.

#### 2º Passo
- _Reviewers_: São os responsáveis por verificar o  _Pull Request_.
- Assinalar os responsáveis para verificar e validar o  _Pull Request_

#### 3º Passo
- _Assignees_: São os responsáveis pelo  _Pull Request_.
- Assinalar os responsáveis e colaboradores do _Pull Request_

#### 4º Passo
- Passo importantíssimo para a organização do _Pull Request_ dentro do repositório.
- Buscar responder as perguntas: **O que é** este _Pull Request_? Ele se encontra **Em Atraso** ? Quem é o **grupo responsável** ? Existe algum **papel específico** para resolução deste _Pull Request_ ?  A que **grande área** pertence esse' _Pull Request_ ? Quais resoluções este _Pull Request_ Implementa?.

#### 5º Passo
- Conectar o _Pull Request_ com a _Issue_ correspondente.
- Utilizando ZenHub ou palavras chaves de fechamento de issues como: **close, closes, fix, fixes** entre **[outras](https://help.github.com/articles/closing-issues-using-keywords/)**.

##  Dependências
- Ferramentas necessárias:
  - [C++](http://www.cplusplus.com/)
  - [SFML](https://www.sfml-dev.org/)
  - [CPPLinter]((https://github.com/cpplint/cpplint)
  - [Catch](https://github.com/catchorg/Catch2)
  - [Gcov](http://gcc.gnu.org/onlinedocs/gcc/Gcov.html)
  - [CPPcheck](http://cppcheck.sourceforge.net/)
