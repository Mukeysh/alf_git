
$(document).ready(function() {
//js for remove login new account
$('#block-user-0 li:first-child').hide();

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

//js for chnage requested password text
$('#block-user-0 li:last-child a').text('Forgot your password?');
});
