/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



LinkedList* ll_newLinkedList(void);//crea una lista en memoria dinamica


int ll_len(LinkedList* this);//cantidad de elementos en la lista


Node* test_getNode(LinkedList* this, int nodeIndex);


int test_addNode(LinkedList* this, int nodeIndex,void* pElement);


int ll_add(LinkedList* this, void* pElement);//agrega empleados


void* ll_get(LinkedList* this, int index);//devuelve un empleado


int ll_set(LinkedList* this, int index,void* pElement);//remplaza un elemento de la lista por otro, recibe lalista, el indice y un elemento


int ll_remove(LinkedList* this,int index);//remueve el elemento seleccionado VER POP


int ll_clear(LinkedList* this);//limpia la lista, la puedo seguir usando


int ll_deleteLinkedList(LinkedList* this);//elimina la lista, NO LA  puedo seguir usando


int ll_indexOf(LinkedList* this, void* pElement);//le paso un empleado y me dice enq direccion esta, -1 si no existe


int ll_isEmpty(LinkedList* this);//me dice si lalista esta vacio o no, antes de listar o ordenar pregunto si la lista esta vacia


int ll_push(LinkedList* this, int index, void* pElement);//agrega un elemento entre 2 recibe lalista, el indice y un elemento


void* ll_pop(LinkedList* this,int index);//remueve el elemento de la lista, pero lo muestra
                                         //puedo sacar tambien un elemento de una lista, para pasarlo a otra pop+add


int ll_contains(LinkedList* this, void* pElement);//si un elemento en particular esta en la lista


int ll_containsAll(LinkedList* this,LinkedList* this2);//si todos los elementos de la lista 2, esta en la lista1


LinkedList* ll_subList(LinkedList* this,int from,int to);//le paso una lista y quiero una lista mas chica desde x hasta y


LinkedList* ll_clone(LinkedList* this);//crea una cpia identica de una lista, sirve para ordenar sin alterar la lista original


int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//ordena la lista, mviendo las direcciones de memoria, sin importar
                                                                     //el dato de adentro, recibe un puntero a funcion, que apunta a la logica
                                                                     //del criterio que va a utilizar el sort ej 16-4
