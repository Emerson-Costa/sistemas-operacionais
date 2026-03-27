#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h> // kmalloc e kfree (Alocação e liberação da memória)

struct birthday {
    int month;
    int day;
    int year;
    struct list_head list;
};

static LIST_HEAD(birthday_list);

int simple_init(void) {
    struct birthday *person;
    int i;

    printk(KERN_INFO "Loading Module\n");

    // Loop para inserir três pessoas na lista
    for (i = 0; i < 3; i++) {
        // Alocando memória para cada nó
        person = kmalloc(sizeof(*person), GFP_KERNEL);
        person->day = 2 + i;
        person->month = 8;
        person->year = 1995 + i;
        
        // Inicializa a estrutura de lista dentro do nó
        INIT_LIST_HEAD(&person->list);
        
        // Adiciona à lista global
        list_add_tail(&person->list, &birthday_list);
    }

    // Varredura para imprimir
    list_for_each_entry(person, &birthday_list, list) {
        printk(KERN_INFO "Birthday: Month %d Day %d Year %d\n", person->month, person->day, person->year);
    }

    return 0;
}

void simple_exit(void) {
    struct birthday *ptr, *next;

    printk(KERN_INFO "Removing Module\n");

    // Liberando a memória para cada elemento da lista
    list_for_each_entry_safe(ptr, next, &birthday_list, list) {
        printk(KERN_INFO "Freeing node: Day %d\n", ptr->day);
        list_del(&ptr->list);
        kfree(ptr);
    }
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Data Structures Lab");
MODULE_AUTHOR("Emerson_Costa");
