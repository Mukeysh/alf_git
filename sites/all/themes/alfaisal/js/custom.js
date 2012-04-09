
$(document).ready(function() {
//js for remove login new account
$('#block-user-0 .item-list li:first-child').css('display','none');

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
$('#block-user-0 .item-list li:last-child a').text('Forgot your password?');
//js for remove search ":"
$('#search #edit-search-theme-form-1-wrapper label').text('Search');
//js for removing ':' for login form
$('#block-user-0 #edit-name-wrapper label').text('Username');
$('#block-user-0 #edit-pass-wrapper label').text('Password');
});
