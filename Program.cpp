using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        List<string> tarefas = new List<string>();  
        int opcao;

        do
        {
            Console.WriteLine("Gerenciador de Tarefas");
            Console.WriteLine("1. Adicionar tarefa");
            Console.WriteLine("2. Listar tarefas");
            Console.WriteLine("3. Remover tarefa");
            Console.WriteLine("4. Sair");
            Console.Write("Escolha uma opção: ");

            // Input validation for option
            if (!int.TryParse(Console.ReadLine(), out opcao))
            {
                Console.WriteLine("Por favor, insira um número válido.");
                continue;
            }

            switch (opcao)
            {
                case 1:
                    Console.Write("Digite a tarefa a ser adicionada: ");
                    string tarefa = Console.ReadLine();
                    if (!string.IsNullOrWhiteSpace(tarefa))
                    {
                        tarefas.Add(tarefa);
                        Console.WriteLine("Tarefa adicionada com sucesso!");
                    }
                    else
                    {
                        Console.WriteLine("Tarefa não pode estar vazia.");
                    }
                    break;

                case 2:
                    Console.WriteLine("Lista de Tarefas:");
                    if (tarefas.Count == 0)
                    {
                        Console.WriteLine("Nenhuma tarefa cadastrada.");
                    }
                    else
                    {
                        for (int i = 0; i < tarefas.Count; i++)
                        {
                            Console.WriteLine($"{i + 1}. {tarefas[i]}");
                        }
                    }
                    break;

                case 3:
                    Console.Write("Digite o número da tarefa a ser removida: ");
                    if (int.TryParse(Console.ReadLine(), out int indice) && indice > 0 && indice <= tarefas.Count)
                    {
                        tarefas.RemoveAt(indice - 1);
                        Console.WriteLine("Tarefa removida com sucesso!");
                    }
                    else
                    {
                        Console.WriteLine("Índice inválido! Tente novamente.");
                    }
                    break;

                case 4:
                    Console.WriteLine("Saindo...");
                    break;

                default:
                    Console.WriteLine("Opção inválida! Tente novamente.");
                    break;
            }

            Console.WriteLine();
        } while (opcao != 4);
    }
}
