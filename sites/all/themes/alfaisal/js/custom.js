//js for remove login new account
$('#sidebar-first .block-inner .item-list li:first').css('display','none');

//jquey for chrome
if (navigator.userAgent.toLowerCase().indexOf("chrome") >= 0) {
                $(window).load(function(){
                    $('input:-webkit-autofill').each(function(){
                        var text = $(this).val();
                        var name = $(this).attr('name');
                        $(this).after(this.outerHTML).remove();
                        $('input[name=' + name + ']').val(text);
                    });
});}


