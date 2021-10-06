/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


if (window.location.href.indexOf('#') !== -1) {
  const sectionName = window.location.href.split('#').at(-1)
  const link = document.getElementById(sectionName);
  
  if (link) {
    const section = link.closest('.card');
    const content = section.querySelector('.card-body')
    link.setAttribute("aria-expanded", true);
    content.classList.add("show");
  }
}